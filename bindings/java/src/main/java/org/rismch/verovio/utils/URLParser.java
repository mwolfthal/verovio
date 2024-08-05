package org.rismch.verovio.utils;

import org.jetbrains.annotations.NotNull;
import org.jetbrains.annotations.Nullable;
import org.rismch.verovio.Constants;
import org.rismch.verovio.VrvException;

import java.io.File;
import java.net.URI;
import java.net.URL;
import java.net.URLEncoder;
import java.net.URLStreamHandler;
import java.nio.charset.StandardCharsets;

public class URLParser
{
    private static final String CLASSPATH_SCHEME = "classpath";
    public static final String CLASSPATH_SCHEME_COLON =
        CLASSPATH_SCHEME + Constants.COLON_STR;
    private static final String FILE_SCHEME = "file";
    public static final String FILE_SCHEME_COLON =
        FILE_SCHEME + Constants.COLON_STR;

    private static final String HTTP_SCHEME = "http";
    private static final String HTTP_SCHEME_COLON =
        HTTP_SCHEME + Constants.COLON_STR;

    public static final String HTTPS_SCHEME = "https";
    private static final String HTTPS_SCHEME_COLON =
        HTTPS_SCHEME + Constants.COLON_STR;

    private static final String DOT_JAR_EXTENSION = ".jar";
    private static final String JAR_SCHEME = "jar";
    public static final String JAR_SCHEME_COLON =
        JAR_SCHEME + Constants.COLON_STR;

    public static final String JAR_FILE_COMPOSITE_SCHEME_COLON =
        JAR_SCHEME_COLON + FILE_SCHEME_COLON;
    public static final String JAR_CONTENTS_SEPARATOR = "!/";

    /**
     * This does not validate a URL, it merely extracts the protocol.
     */
    public enum URLScheme
    {
        Classpath( CLASSPATH_SCHEME ),
        File( FILE_SCHEME ),
        Jar( JAR_SCHEME ),
        Http( HTTP_SCHEME ),
        Https( HTTPS_SCHEME ),
        Unknown( Constants.EMPTY_STRING );

        private final String scheme;

        URLScheme( String scheme )
        {
            this.scheme = scheme;
        }

        public String getScheme()
        {
            return scheme;
        }

        /**
         * find the enum value from a scheme string
         *
         * @param scheme
         * @return URLScheme
         * @throws VrvException
         */
        @NotNull
        public static URLParser.URLScheme findURLScheme( @NotNull final String scheme )
            throws VrvException
        {
            CommonUtil.notNullOrEmpty( scheme, "scheme is null or empty" );
            URLScheme urlScheme = URLScheme.Unknown;
            for ( URLScheme uS : values() )
            {
                // case sensitive
                if ( uS.scheme.equals( scheme ) )
                {
                    urlScheme = uS;
                    break;
                }
            }
            return urlScheme;
        }

        /**
         * extract the scheme from a @{code URL}
         *
         * @param url
         * @return URLScheme
         * @throws VrvException
         */
        @NotNull
        public static URLParser.URLScheme extractURLSchemeFromURL( @NotNull final URL url )
            throws VrvException
        {
            CommonUtil.notNull( url, "url is null" );
            String protocol = url.getProtocol();
            URLScheme urlScheme = URLScheme.Unknown;
            for ( URLScheme uS : values() )
            {
                // case sensitive
                if ( uS.scheme.equals( protocol ) )
                {
                    urlScheme = uS;
                    break;
                }
            }
            return urlScheme;
        }

        /**
         * Extract the scheme from a URL specification
         *
         * @param resourceSpec
         * @return
         * @throws VrvException
         */
        @NotNull
        public static URLParser.URLScheme extractURLSchemeFromResourceSpec(
            @NotNull final String resourceSpec )
            throws VrvException
        {
            ObjHolder<URLScheme> urlSchemeHolder = new ObjHolder<>();
            parseResourceSpec( resourceSpec, urlSchemeHolder );
            return urlSchemeHolder.getObj();
        }
    } // end enum URLScheme

    public static String extractScheme(
        @NotNull final URL url )
        throws VrvException
    {
        CommonUtil.notNull( url, "url is null or empty" );
        String scheme;
        try
        {
            scheme = url.toURI().getScheme();
        }
        catch ( Exception e )
        {
            throw new VrvException( e );
        }
        return scheme;
    }

    public static URL parseResourceSpec(
        @NotNull final String resourceSpec )
        throws VrvException
    {
        return parseResourceSpec( resourceSpec, null );
    }

    /**
     * Since the URL constructors have beed deprecated
     * this method makes certain that the input is converted to URI syntax
     * with forward slashes. URLs arn now {new URI(uriString).toURL()}
     *
     * @param resourceSpec
     * @param urlSchemeHolder
     * @return URL
     * @throws VrvException
     */
    public static URL parseResourceSpec(
        @NotNull final String resourceSpec,
        @Nullable final ObjHolder<URLScheme> urlSchemeHolder )
        throws VrvException
    {
        CommonUtil.notNullOrEmpty( resourceSpec, "resourceSpec is null or empty" );
        URL url;
        try
        {
            // uri format with forward slashes
            String uriForm = CommonUtil.backToForward( resourceSpec ).trim();
            String[] components = resourceSpec.split( Constants.COLON_STR, 2 );
            url = switch ( components.length )
            {
                case 1 -> fromFilePath( uriForm, urlSchemeHolder );
                case 2 ->
                {
                    // where the first component is a drive letter, as in C:/tmp
                    if ( components[0].length() == 1 )
                    {
                        url = fromFilePath( uriForm, urlSchemeHolder );
                    }
                    else
                    {
                        url = fromSchemeAndPath( resourceSpec, urlSchemeHolder );
                    }
                    yield url;
                }
                default -> throw new VrvException(
                    "Unexpected components length: " + components.length );
            };
        }
        catch ( Exception e )
        {
            throw new VrvException( e );
        }
        return url;
    }

    /**
     * produce a jar or file URL
     * filePath with URI syntax: forward slashes
     */
    private static URL fromFilePath(
        @NotNull final String filePath,
        @Nullable final ObjHolder<URLScheme> urlSchemeHolder )
        throws Exception
    {
        URL url;
        if ( filePath.endsWith( DOT_JAR_EXTENSION ) )
        {
            url = new URI( urlEncodeSpace( JAR_FILE_COMPOSITE_SCHEME_COLON +
                                           filePath + JAR_CONTENTS_SEPARATOR ) ).toURL();
            if ( null != urlSchemeHolder )
            {
                urlSchemeHolder.setObj( URLScheme.Jar );
            }
        }
        else
        {
            url = new URI( urlEncodeSpace(
                FILE_SCHEME_COLON + filePath ) ).toURL();
            if ( null != urlSchemeHolder )
            {
                urlSchemeHolder.setObj( URLScheme.File );
            }
        }
        return url;
    }

    private static URL fromSchemeAndPath(
        @NotNull final String resourceSpec,
        @Nullable final ObjHolder<URLScheme> urlSchemeHolder )
        throws Exception
    {
        String[] components = resourceSpec.split( Constants.COLON_STR, 2 );
        URLScheme urlScheme = URLScheme.findURLScheme( components[0] );
        URL url = switch ( urlScheme )
        {
            case Classpath -> handleClasspathURL( resourceSpec );
            case Jar -> fromJarURL( resourceSpec );
            // just restore the original spec
            case File -> new URI( urlEncodeSpace(
                components[0] + Constants.COLON_STR + components[1] ) ).toURL();
            case Http, Https -> new URI(
                URLEncoder.encode( components[0] +
                                   Constants.COLON_STR + components[1],
                    StandardCharsets.UTF_8 ) ).toURL();
            case Unknown -> throw new Exception( "Unknown scheme in " + resourceSpec );
        };
        if ( null != urlSchemeHolder )
        {
            urlSchemeHolder.setObj( urlScheme );
        }
        return url;
    }

    /**
     * This method returns a URL that will trigger the
     * {@link ClasspathURLStreamHandlerProvider}
     * <p>
     * Called by {@code LogUtil.initLogger()} so no {@code static Logger}
     * in this class.
     */
    private static URL makeClasspathURL( @NotNull final String resourceSpec )
        throws VrvException
    {
        ObjHolder<URLScheme> urlSchemeHolder = new ObjHolder<>();
        URL url = parseResourceSpec( resourceSpec, urlSchemeHolder );
        if ( null == url || urlSchemeHolder.getObj() != URLScheme.Classpath )
        {
            throw new VrvException( "failed to create classpath URL for '" + resourceSpec + "'" );
        }
        return url;
    }

    private static URL handleClasspathURL(
        @NotNull final String resourceSpec )
        throws VrvException
    {
        CommonUtil.notNullOrEmpty( resourceSpec, "resourceSpec" );
        final URLStreamHandler handler =
            new ClasspathURLStreamHandlerProvider.ClasspathURLStreamHandler();
        String uriSpec = CommonUtil.backToForward( resourceSpec );
        URL url;
        try
        {
            url = URL.of( new URI( uriSpec ), handler );
        }
        catch ( Exception e )
        {
            throw new VrvException( e );
        }
        return url;
    }

    /**
     * replace spaces with "%20"
     */
    public static String urlEncodeSpace( @NotNull final String resourceSpec )
    {
        return resourceSpec.replace( Constants.SPACE_STR, Constants.SPACE_URLENCODE );
    }

    private static URL fromJarURL( @NotNull final String resourceSpec )
        throws VrvException
    {
        CommonUtil.notNullOrEmpty( resourceSpec, "resourceSpec" );
        URL url;
        try
        {
            StringPair canonicalPathAndEntry =
                extractCanonicalPathAndEntry( resourceSpec );
            String canonicalPath = canonicalPathAndEntry.getO1();
            String initialEntryName = canonicalPathAndEntry.getO2();
            url = new URL( JAR_FILE_COMPOSITE_SCHEME_COLON +
                           canonicalPath + JAR_CONTENTS_SEPARATOR +
                           initialEntryName );
        }
        catch ( Exception e )
        {
            throw new VrvException( e );
        }
        return url;
    }

    private static StringPair extractCanonicalPathAndEntry(
        @NotNull final String resourceSpec )
        throws VrvException
    {
        StringPair canonicalPathAndEntry = new StringPair();
        try
        {
            CommonUtil.notNull( resourceSpec, "resourceSpec" );
            String pathWithPossibleEntry;
            if ( resourceSpec.startsWith( JAR_SCHEME_COLON ) )
            {
                // first remove "jar:"
                pathWithPossibleEntry = resourceSpec.replace( JAR_SCHEME_COLON,
                    Constants.EMPTY_STRING );
                // then the secondary protocol
                String protocolColon =
                    URLScheme.extractURLSchemeFromResourceSpec( pathWithPossibleEntry ).
                        getScheme() + Constants.COLON_STR;
                if ( pathWithPossibleEntry.startsWith( protocolColon ) )
                {
                    pathWithPossibleEntry = pathWithPossibleEntry.replace( protocolColon,
                        Constants.EMPTY_STRING );
                }
            }
            else
            {
                pathWithPossibleEntry = resourceSpec;
            }

            String filePath;
            // a null after the separator will cause an error
            String entryName = Constants.EMPTY_STRING;
            // the jar is everything before the separator
            // the entry is anything found after
            if ( pathWithPossibleEntry.contains( DOT_JAR_EXTENSION + JAR_CONTENTS_SEPARATOR ) )
            {
                int separatorIndex = pathWithPossibleEntry.indexOf( JAR_CONTENTS_SEPARATOR );
                int entryIndex = separatorIndex + JAR_CONTENTS_SEPARATOR.length();
                // if there is an entry
                if ( pathWithPossibleEntry.length() > entryIndex )
                {
                    entryName = pathWithPossibleEntry.substring( entryIndex );
                }
                // now strip it off
                filePath = pathWithPossibleEntry.substring( 0, separatorIndex );
            }
            else
            {
                filePath = pathWithPossibleEntry;
            }
            File file = new File( filePath );
            String canonicalPath = file.getCanonicalPath();
            canonicalPathAndEntry.setObjects( canonicalPath, entryName );
        }
        catch ( Exception e )
        {
            throw new VrvException( e.getMessage() );
        }
        return canonicalPathAndEntry;
    }
}

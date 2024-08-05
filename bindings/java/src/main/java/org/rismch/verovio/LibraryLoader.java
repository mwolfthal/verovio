package org.rismch.verovio;

import org.jetbrains.annotations.NotNull;
import org.rismch.verovio.logging.LogUtil;
import org.rismch.verovio.utils.CommonUtil;
import org.slf4j.Logger;

class LibraryLoader
{
    private static Logger logger;

    static
    {
        try
        {
            logger = LogUtil.getLogger( LibraryLoader.class );
        }
        catch ( Exception e )
        {
            throw new VrvRuntimeException( e );
        }
    }

    private LibraryLoader()
    {
    }

    static void loadLibrary()
        throws VrvException
    {
        String soPath = Constants.VEROVIO_SO_PATH;
        if ( CommonUtil.isNullOrEmpty( soPath ) )
        {
            throw new VrvException( Constants.PN_VEROVIO_SO_DIR + " has not been set" );
        }
        else
        {
            loadLibrary( soPath );
        }
    }

    static void loadLibrary( @NotNull final String soPath )
        throws VrvException
    {
        if ( CommonUtil.isNullOrEmpty( soPath ) )
        {
            throw new VrvException( "shared library path is null or empty" );
        }
        String absolutePath = null;
        try
        {
            logger.info( "Loading library {}", soPath );

//            List<URLParser.URLProtocol> supportedProtocols =
//                new ArrayList<>
//                    (
//                        Arrays.asList(
//                            new URLParser.URLProtocol[]
//                                {
//                                    URLParser.URLProtocol.Classpath,
//                                    URLParser.URLProtocol.File
//                                }
//                        )
//                    );
//            ObjHolder<URLParser.URLProtocol> protocolHolder = new ObjHolder<>();
//            URL libraryURL = URLParser.parseResourceSpec( path, protocolHolder );
//            URLParser.URLProtocol protocol = protocolHolder.getObj();
//            if ( !supportedProtocols.contains( protocol ) )
//            {
//                throw new VrvException( protocol.getProtocol() + "URL is not supported" );
//            }
//            String soPath = libraryURL.getPath();
            absolutePath = CommonUtil.checkFileER( soPath );
            assert ( !CommonUtil.isNullOrEmpty( absolutePath ) );
            if ( !absolutePath.endsWith( Constants.JNI_LIBRARY_NAME ) )
            {
                throw new VrvException( "library path must end with " +
                                        Constants.JNI_LIBRARY_NAME );
            }
            System.load( absolutePath );
            logger.info( "loaded Shared Library {}", absolutePath );
        }
        catch ( Exception e )
        {
            logger.error( "failed to load shared library from {} ", absolutePath );
            throw new VrvException( e );
        }
    }
}


package org.rismch.verovio;

import com.weichi.utils.CommonUtil;
import com.weichi.utils.io.FileUtil;
import com.weichi.utils.io.ResourceUtil;
import com.weichi.utils.io.URLParser;
import com.weichi.utils.logging.LogUtil;
import org.apache.commons.lang3.SystemUtils;
import org.jetbrains.annotations.NotNull;
import org.slf4j.Logger;

import java.net.URL;

public class LibraryLoader
{
    private static final Logger logger;

    static
    {
        try
        {
            logger = LogUtil.getLogger( LibraryLoader.class );
        }
        catch ( Exception e )
        {
            throw new VrvRuntimeException( e.getMessage() );
        }
    }

    private LibraryLoader()
    {
    }

    public static void loadLibrary()
        throws VrvException
    {
        String soPath = System.getProperty( Constants.PN_VEROVIO_SO_PATH );
        if ( CommonUtil.isNullOrEmpty( soPath ) )
        {
            throw new VrvException( "SystemProperty " + Constants.PN_VEROVIO_SO_PATH +
                                    " has not been set" );
        }
        else
        {
            loadLibrary( soPath );
        }
    }

    public static void loadLibrary( @NotNull final String path )
        throws VrvException
    {
        if ( CommonUtil.isNullOrEmpty( path ) )
        {
            throw new VrvException( "shared library path is null or empty" );
        }

        try
        {
            URL url = ResourceUtil.makeURL( path );
            URLParser.URLProtocol urlProtocol = URLParser.URLProtocol.extractProtocol( url );
            if ( urlProtocol != URLParser.URLProtocol.File )
            {
                throw new VrvException( "path must point to the library file" );
            }
            String librarySuffix;
            if ( SystemUtils.IS_OS_LINUX )
            {
                librarySuffix = Constants.LINUX_SHARED_LIBRARY_DOT_SUFFIX;
            }
            else if ( SystemUtils.IS_OS_WINDOWS )
            {
                librarySuffix = Constants.WINDOWS_SHARED_LIBRARY_DOT_SUFFIX;
            }
            else
            {
                throw new VrvException( "Unsupported OS" );
            }
            String soPath = url.getPath();
            if ( !soPath.endsWith( librarySuffix ) )
            {
                throw new VrvException( "library path must end with " + librarySuffix );
            }
            String absolutePath = FileUtil.checkFileER( soPath );
            System.load( absolutePath );
            logger.info( "loaded Shared Library from " + absolutePath );
        }
        catch ( Exception e )
        {
            logger.error( "failed to load shared library" );
            throw new VrvException( e );
        }
    }
}


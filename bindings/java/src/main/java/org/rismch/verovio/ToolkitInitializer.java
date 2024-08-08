package org.rismch.verovio;

import org.apache.commons.lang3.SystemUtils;
import org.jetbrains.annotations.NotNull;
import org.rismch.verovio.logging.LogUtil;
import org.rismch.verovio.utils.CommonUtil;
import org.slf4j.Logger;

import java.io.File;
import java.util.concurrent.atomic.AtomicBoolean;

public final class ToolkitInitializer
{
    static Logger logger = null;
    static
    {
        try
        {
            LogUtil.initLogger();
            logger = LogUtil.getLogger( ToolkitInitializer.class );
        }
        catch ( Exception e )
        {
            throw new VrvRuntimeException( e );
        }
    }

    private static final AtomicBoolean isInitialized = new AtomicBoolean( false );

    public static void initialize()
        throws VrvException
    {
        try
        {
            String soPath = getLibraryPath();
            // use load() with full path, not loadLibrary()
            System.load( soPath );
            isInitialized.set( true );
        }
        catch ( Exception e )
        {
            logger.error( e.getMessage() );
            throw e;
        }
    }

    public static boolean isInitialized()
    {
        return isInitialized.get();
    }

    private static String getLibraryPath()
        throws VrvException
    {
        // full path to the native library
        String verovioSoPath;
        String jniLibraryBasename = "VerovioJni";
        String jniLibraryName;
        String unixSoPrefix = "lib";
        String unixSoDotSuffix = ".so";
        String windowsSoDotSuffix = ".dll";
        String soDir = System.getProperty( Constants.PN_VEROVIO_SO_DIR );
        CommonUtil.notNullOrEmpty( soDir, "SystemProperty " +
                                          Constants.PN_VEROVIO_SO_DIR );

        String libDirAbsolutePath = CommonUtil.checkDirER( soDir );
        if ( SystemUtils.IS_OS_WINDOWS )
        {
            jniLibraryName =
                jniLibraryBasename + windowsSoDotSuffix;
        }
        else
        {
            jniLibraryName =
                unixSoPrefix + jniLibraryBasename + unixSoDotSuffix;
        }
        verovioSoPath = libDirAbsolutePath + File.separator + jniLibraryName;
        return verovioSoPath;
    }
}

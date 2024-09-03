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
    // this includes the library file
    private static String verovioLibraryPath;
    private static String verovioDataDir;

    static Logger logger;

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

    /**
     * Initialize the toolkit
     *
     * @throws VrvException if the shared library or data paths are
     *                      invalid or there is an error loading the library
     */
    public static void initialize()
        throws VrvException
    {
        try
        {
            verovioLibraryPath = getLibraryPath();
            verovioDataDir = getDataDir();
            // use load() with full path, not loadLibrary()
            if ( logger.isInfoEnabled() )
            {
                logger.info( "loading JNI library from " + verovioLibraryPath );
            }
            System.load( verovioLibraryPath );
            isInitialized.set( true );
        }
        catch ( Exception e )
        {
            logger.error( e.getMessage() );
            throw new VrvException( e );
        }
    }

    public static boolean isInitialized()
    {
        return isInitialized.get();
    }

    @NotNull
    public static String getVerovioLibraryPath()
    {
        return verovioLibraryPath;
    }

    @NotNull
    public static String getVerovioDataDir()
    {
        return verovioDataDir;
    }

    /**
     * Determine the path to the shared library from the
     * {@code SystemProperty} and append the library suffix
     * depending on the OS.
     *
     * @return {@link String} the path to the shared library
     * @throws VrvException if the {@code SystemProperty} is not set
     *                      or invalid
     */
    private static String getLibraryPath()
        throws VrvException
    {
        // full path to the native library
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
        return libDirAbsolutePath + File.separator + jniLibraryName;
    }

    /**
     * Determine the location of the Verovio data directory
     * from the {@code SystemProperty}
     *
     * @return {@link String}
     * @throws VrvException if the {@code SystemProperty} is not set
     *                      or the path is invalid
     */
    private static String getDataDir()
        throws VrvException
    {
        // full path to the native library
        String verovioDataDirAbsolutePath;
        String dataDir = System.getProperty( Constants.PN_VEROVIO_DATA_DIR );
        CommonUtil.notNullOrEmpty( dataDir, "SystemProperty " +
            Constants.PN_VEROVIO_DATA_DIR );
        return CommonUtil.checkDirER( dataDir );
    }
}

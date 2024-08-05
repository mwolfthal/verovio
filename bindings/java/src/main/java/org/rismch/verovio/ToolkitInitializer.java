package org.rismch.verovio;

import org.jetbrains.annotations.NotNull;
import org.rismch.verovio.logging.LogUtil;

import java.util.concurrent.atomic.AtomicBoolean;

public final class ToolkitInitializer
{
    static
    {
        try
        {
            LogUtil.initLogger();
        }
        catch ( Exception e )
        {
            throw new VrvRuntimeException( e );
        }
    }
    private static final AtomicBoolean isInitialized = new AtomicBoolean( false );
    public static void initialize() throws VrvException
    {
        LibraryLoader.loadLibrary();
        isInitialized.set( true );
    }

    public static void initialize( @NotNull final String soPath ) throws VrvException
    {
        LibraryLoader.loadLibrary( soPath );
        isInitialized.set( true );
    }

    public static boolean isInitialized()
    {
        return isInitialized.get();
    }
}

/*
 * Copyright (c) 2005 - 2023 Marvin Wolfthal.  All Rights Reserved.
 */

package org.rismch.verovio.utils;

import org.jetbrains.annotations.NotNull;
import org.rismch.verovio.Constants;
import org.rismch.verovio.VrvException;
import org.rismch.verovio.VrvRuntimeException;

import java.io.IOException;
import java.net.URL;
import java.net.URLConnection;
import java.net.URLStreamHandler;
import java.net.spi.URLStreamHandlerProvider;

/**
 * Note that we can't define a Logger for this class because
 * if {@code LogUtil.initLogger(}} is called with a {@code classpath:}
 * argument this class will be called to resolve it and {@code getLogger()}
 * will fail.
 */
public class ClasspathURLStreamHandlerProvider extends URLStreamHandlerProvider
{
    public ClasspathURLStreamHandlerProvider()
    {
    }

    @Override
    public URLStreamHandler createURLStreamHandler(
        @NotNull final String protocol ) throws VrvRuntimeException
    {
        URLStreamHandler urlStreamHandler = null;
        try
        {
            CommonUtil.notNullOrEmpty( protocol, "protocol" );
            if ( protocol.equals( Constants.CLASSPATH_PROTOCOL ) )
            {
                urlStreamHandler = new ClasspathURLStreamHandler();
            }
        }
        catch ( Exception e )
        {
            throw new VrvRuntimeException( e );
        }
        return urlStreamHandler;
    }

    public static class ClasspathURLStreamHandler extends URLStreamHandler
    {
        @Override
        protected URLConnection openConnection( @NotNull final URL url )
            throws IOException
        {
            URLConnection connection = null;
            String path = url.getPath();
            ClassLoader classLoader =
                //Thread.currentThread().getContextClassLoader();
                getClass().getClassLoader();
            URL resourceURL = classLoader.getResource( path );
            if ( null != resourceURL )
            {
                connection = resourceURL.openConnection();
            }
            return connection;
        }
    }
}

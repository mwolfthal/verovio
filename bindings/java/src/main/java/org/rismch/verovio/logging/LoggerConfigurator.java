/*
 * Copyright (c) 2005 - 2023 Marvin Wolfthal.  All Rights Reserved.
 */

package org.rismch.verovio.logging;
import org.jetbrains.annotations.NotNull;
import org.jetbrains.annotations.Nullable;
import org.rismch.verovio.VrvException;
import org.rismch.verovio.utils.CommonUtil;
import org.rismch.verovio.utils.URLParser;

import java.io.File;
import java.io.InputStream;
import java.net.URL;
import java.net.URLConnection;

/**
 * @author Marvin Wolfthal
 * @since 1/13/2020
 */
class LoggerConfigurator
{
    private static final String PN_LOGBACK_CONFIGURATION_FILE =
        "logback.configurationFile";
    private static final String LOGBACK_XML = "logback.xml";
    static void configureLogger( @Nullable Object configSpec ) throws VrvException
    {
        if ( null == configSpec ||
            ( configSpec.getClass() == String.class &&
                ( (String) configSpec ).isEmpty() ) )
        {
            configureFromNull();
        }
        else
        {
            switch ( configSpec.getClass().getName() )
            {
                case "String" -> configureFromString( configSpec.toString() );
                case "URL" -> configureFromURL( (URL) configSpec );
            }
        }
        LogUtil.isConfigured();
    }

    private static void configureFromNull()
    {
        // check the System properties
        if ( CommonUtil.isNullOrEmpty(
            System.getProperty( PN_LOGBACK_CONFIGURATION_FILE ) ) )
        {
            // check the environment
            String s = System.getenv( PN_LOGBACK_CONFIGURATION_FILE );
            if ( CommonUtil.isNullOrEmpty( s ) )
            {
                // use the default file name and assume current directory
                s = LOGBACK_XML;
            }
            System.setProperty( PN_LOGBACK_CONFIGURATION_FILE, s );
        }
    }

    static void configureFromString( @NotNull final String configString )
    {
        System.setProperty( PN_LOGBACK_CONFIGURATION_FILE, configString );
    }

    static void configureFromURL( @NotNull final URL configURL )
        throws VrvException
    {
        String configFile = "";
        switch ( URLParser.URLScheme.extractURLSchemeFromURL( configURL ) )
        {
            case File -> configFile = new File( configURL.getPath() ).getAbsolutePath();
            case Jar -> configFile = configURL.toExternalForm();
        }
        if ( !CommonUtil.isNullOrEmpty( configFile ) )
        {
            CommonUtil.checkFileER( configFile );
        }
        else
        {
            configFile = LOGBACK_XML;
        }
        System.setProperty( PN_LOGBACK_CONFIGURATION_FILE, configFile );
    }

    /**
     * rewrite the URL, necessary if it is "classpath:"
     *
     * @param configURL the input as URL
     * @return URL
     */
    @NotNull
    private static URL decodeConfigURL( @NotNull final URL configURL )
    {
        URL decodedURL = null;
        try
        {
            URLConnection urlConnection = configURL.openConnection();
            if ( null != urlConnection )
            {
                InputStream inputStream = urlConnection.getInputStream();
                decodedURL = urlConnection.getURL();
                inputStream.close();
            }
            else
            {
                throw new Exception();
            }
        }
        catch ( Exception ignored )
        {
            decodedURL = configURL;
        }
        return decodedURL;
    }
}

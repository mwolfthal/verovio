/*
 * Copyright (c) 2005 Marvin Wolfthal. All Rights Reserved.
 */
package org.rismch.verovio.logging;

import org.jetbrains.annotations.NotNull;
import org.jetbrains.annotations.Nullable;
import org.rismch.verovio.Constants;
import org.rismch.verovio.VrvException;
import org.rismch.verovio.utils.CommonUtil;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.slf4j.helpers.NOPLogger;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.concurrent.atomic.AtomicBoolean;
import org.rismch.verovio.Constants;

/**
 * This class configures slf4j to use logback
 **/
public final class LogUtil
{
    private static final AtomicBoolean isConfigured = new AtomicBoolean( false );
    private static final AtomicBoolean isLogbackStatusLogged = new AtomicBoolean( false );

    private LogUtil()
    {
    }

    public synchronized static void initLogger()
        throws VrvException
    {
        LogUtil.initLogger( (String) null );
    }

    public synchronized static void initLogger( @Nullable final Object configFileSpec )
        throws VrvException
    {
        // already configured
        if ( getIsConfigured() )
        {
            return;
        }
        StringBuilder configMessageSB = new StringBuilder();
        try
        {
            LoggerConfigurator.configureLogger( configFileSpec );
            if ( !getIsConfigured() )
            {
                throw new Exception( "Failed to configure logger" );
            }
        }
        catch ( Exception e )
        {
            configMessageSB.append( String.format( "%sconfiguration error: %s", configMessageSB.isEmpty() ?
                Constants.EMPTY_STRING : Constants.NEW_LINE_STR, e.getMessage() ) );
            throw new VrvException( configMessageSB.toString() );
        }
        // to call getLogger()
        Logger testLogger = LogUtil.getLogger( LogUtil.class );
        if ( null == testLogger || testLogger instanceof NOPLogger )
        {
            isConfigured.set( false );
            configMessageSB.append( String.format( "%sFailed to create test logger", configMessageSB.isEmpty() ?
                Constants.EMPTY_STRING : Constants.NEW_LINE_STR ) );
            throw new VrvException( configMessageSB.toString() );
        }
        testLogger.info( configMessageSB.toString() );
        // If the underlying logger is not logback then there will
        // be no messages.
        if ( isLogbackStatusLogged.get() )
        {
            String statusMessages = LogbackStatusListener.getStatusMessages();
            if ( !CommonUtil.isNullOrEmpty( statusMessages ) )
            {
                testLogger.info( statusMessages );
            }
        }
    }

    /**
     * Reset the logging system, intended for testing only.
     */
    public static synchronized void unconfigure()
    {
        LogUtil.isConfigured.set( false );
        LogUtil.isLogbackStatusLogged.set( false );
    }

    public static synchronized Logger getLogger( final Class<?> cls )
        throws VrvException
    {
        return LogUtil.getLogger( cls.getName() );
    }

    public static synchronized Logger getLogger( final String name )
        throws VrvException
    {
        if ( !getIsConfigured() )
        {
            throw new VrvException( "LogUtil has not been configured" );
        }
        if ( CommonUtil.isNullOrEmpty( name ) )
        {
            throw new VrvException( "no logger name given" );
        }
        Logger logger;
        try
        {
            logger = LoggerFactory.getLogger( name );
        }
        catch ( Exception e )
        {
            throw new VrvException( "getting Logger for " + name + ":" + e );
        }
        return logger;
    }

    @NotNull
    public static String taskMsg(
        @NotNull final String task,
        @Nullable final Throwable t )
    {
        return LogUtil.taskMsg( null, task, t );
    }

    /**
     * compiles String: In <method>: While <task>: t details
     */
    @NotNull
    public static String taskMsg(
        @Nullable final String method,
        @NotNull final String task,
        @Nullable final Throwable t )
    {
        StringBuilder sb = new StringBuilder();
        if ( !CommonUtil.isNullOrEmpty( method ) )
        {
            sb.append( "In method " ).append( method ).append( ":" );
        }
        sb.append( "While " ).append( task );
        if ( null != t )
        {
            String excData = t.toString();
            if ( !CommonUtil.isNullOrEmpty( excData ) )
            {
                sb.append( ":" ).append( excData );
            }
        }
        return sb.toString();
    }

    /**
     * compiles String: In <method>: While <task>: msg
     */
    @NotNull
    public static String taskMsg(
        @Nullable final String method,
        @NotNull final String task,
        @NotNull final String msg )
    {
        return taskMsg( method, task, msg, null );
    }

    /**
     * compiles String: In <method>: While <task>: msg
     */
    @NotNull
    public static String taskMsg(
        @Nullable final String method,
        @NotNull final String task,
        @NotNull final String msg,
        @Nullable final Throwable t )
    {
        StringBuilder sb = new StringBuilder();
        if ( !CommonUtil.isNullOrEmpty( method ) )
        {
            sb.append( "In method " ).append( method ).append( ": " );
        }
        sb.append( "While " ).append( task ).append( ": " );
        sb.append( msg );
        if ( null != t )
        {
            String excData = t.toString();
            if ( !CommonUtil.isNullOrEmpty( excData ) )
            {
                sb.append( " : " ).append( excData );
            }
        }
        return sb.toString();
    }

    // set to true
    static synchronized void isConfigured()
    {
        LogUtil.isConfigured.set( true );
    }
    public static boolean getIsConfigured()
    {
        return isConfigured.get();
    }
    public static synchronized void isLogbackStatusLogged( boolean isLogged )
    {
        isLogbackStatusLogged.set( isLogged );
    }

    public static synchronized boolean isLogbackStatusLogged()
    {
        return LogUtil.isLogbackStatusLogged.get();
    }

    /**
     * Simple and stupid to frame text
     */
    public static String eyeCatcher( final String text )
    {
        final String EQUALS = "=====================================================================";
        if ( CommonUtil.isNullOrEmpty( text ) )
        {
            return Constants.EMPTY_STRING;
        }
        return Constants.NEW_LINE_STR + Constants.EQUALS_STR +
               Constants.NEW_LINE_STR + text + Constants.NEW_LINE_STR + EQUALS +
               Constants.NEW_LINE_STR;
    }
}

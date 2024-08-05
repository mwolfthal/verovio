/*
 * Copyright (c) 2005 - 2021 Marvin Wolfthal. All Rights Reserved.
 */
package org.rismch.verovio;

import org.jetbrains.annotations.NotNull;
import org.rismch.verovio.utils.CommonUtil;

import java.io.Serial;

/**
 * @author Marvin Wolfthal
 * @since 9/12/2011
 */
public class VrvRuntimeException extends RuntimeException
{
    public VrvRuntimeException()
    {
        super();
    }
    public VrvRuntimeException( String message )
    {
        super( message );
    }

    public VrvRuntimeException( String message, Throwable t )
    {
        super( message + ":" + t.getMessage() );
    }

    public VrvRuntimeException( Throwable t )
    {
        super( t.getMessage() );
    }

    /**
     * If the argument is a VrvException just throw it as is.
     * Otherwise, wrap it in a VrvRuntimeException.
     */
    public static void handleException(
        @NotNull final Throwable t ) throws Exception
    {
        CommonUtil.notNull( t, "Throwable" );
        if ( t instanceof VrvRuntimeException )
        {
            throw (VrvRuntimeException)t;
        }
        else
        {
            throw new VrvRuntimeException( t );
        }
    }

    @Override
    public final String toString()
    {
        StringBuilder sb = new StringBuilder(
            this.getClass().getName() );
        String msg = getMessage();
        if ( !CommonUtil.isNullOrEmpty( msg ) )
        {
            sb.append( ": message: " );
            sb.append( msg );
        }

        // try to avoid duplicate messages
        Throwable t = this.getCause();
        if ( null != t )
        {
            String causeMsg = t.getMessage();
            if ( !CommonUtil.isNullOrEmpty( causeMsg ) &&
                !msg.contains( causeMsg ) )
            {
                sb.append( ": cause: " )
                    .append( t.getClass().getName() )
                    .append( ": cause message: " )
                    .append( causeMsg );
            }
        }
        return sb.toString();
    }
}

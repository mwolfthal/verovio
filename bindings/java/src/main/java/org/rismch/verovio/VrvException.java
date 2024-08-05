
package org.rismch.verovio;

import org.jetbrains.annotations.NotNull;
import org.rismch.verovio.utils.CommonUtil;

import java.io.Serial;

public class VrvException extends Exception
{
    @Serial
    private static final long serialVersionUID = 2522342728178562402L;

    public VrvException()
    {
        super();
    }

    public VrvException( final String message )
    {
        super( message );
    }

    public VrvException( final String message, final Throwable t )
    {
        super( message + ":" + t.getMessage() );
    }

    public VrvException( final Throwable t )
    {
        super( t.getMessage() );
    }

    /**
     * If the argument is an VrvException just throw it as is.
     * Otherwise, wrap it in a VrvException.
     */
    public static void handleException(
        @NotNull final Throwable t ) throws VrvException
    {
        if ( t instanceof VrvException )
        {
            throw (VrvException)t;
        }
        else
        {
            throw new VrvException( t.toString() );
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

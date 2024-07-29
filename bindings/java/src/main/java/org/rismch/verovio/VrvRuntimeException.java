package org.rismch.verovio;

import com.weichi.utils.exceptions.WeichiRuntimeException;

public class VrvRuntimeException extends WeichiRuntimeException
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
        super( message, t );
    }

    public VrvRuntimeException( Throwable t )
    {
        super( t );
    }
}

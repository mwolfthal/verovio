package org.rismch.verovio;

import com.weichi.utils.exceptions.WeichiException;

public class VrvException extends WeichiException
{
    public VrvException()
    {
        super();
    }

    public VrvException( String message )
    {
        super( message );
    }

    public VrvException( String message, Throwable t )
    {
        super( message, t );
    }

    public VrvException( Throwable t )
    {
        super( t );
    }
}

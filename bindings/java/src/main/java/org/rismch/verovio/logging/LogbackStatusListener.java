package org.rismch.verovio.logging;

import ch.qos.logback.core.status.Status;
import ch.qos.logback.core.status.StatusListener;
import org.jetbrains.annotations.NotNull;

public class LogbackStatusListener implements StatusListener
{
    private final static StringBuffer sb = new StringBuffer();

    public LogbackStatusListener()
    {
    }

    @Override
    synchronized public void addStatusEvent( @NotNull final Status status )
    {
        sb.append( status.toString() ).append( "\n" );
    }

    synchronized static String getStatusMessages()
    {
        String statusMessages = sb.toString();
        sb.setLength( 0 );
        return statusMessages;
    }
}

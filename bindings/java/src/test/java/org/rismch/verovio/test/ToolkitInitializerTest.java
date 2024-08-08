package org.rismch.verovio.test;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.TestInfo;
import org.rismch.verovio.ToolkitInitializer;

import static org.junit.jupiter.api.Assertions.*;

public class ToolkitInitializerTest
{
    @Test
    public void testValid( TestInfo testInfo )
    {
        try
        {
            ToolkitInitializer.initialize();
        }
        catch ( Exception e )
        {
            fail( testInfo.getDisplayName() + " got unexpected exception: " +
                  e.getMessage() );
        }
        System.out.println( testInfo.getDisplayName() + " succeeded " );
    }
}

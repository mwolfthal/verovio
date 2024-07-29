package test.rismch.verovio.pae;

import com.weichi.utils.logging.LogUtil;
import org.junit.jupiter.api.Test;
import org.rismch.verovio.LibraryLoader;
import org.rismch.verovio.VrvRuntimeException;
import org.rismch.verovio.toolkit;
import org.slf4j.Logger;

public class PaeTest
{
    private static Logger logger;

    static
    {
        try
        {
            LogUtil.initLogger();
            logger = LogUtil.getLogger( PaeTest.class );
        }
        catch ( Exception e )
        {
            throw new VrvRuntimeException( e.getMessage() );
        }
    }

    @Test
    public void TestPae()
    {
        try
        {
            LibraryLoader.loadLibrary();
            /*
             * create the toolkit and set the resource path
             * (if the fonts are installed (see the ./tools) then there is not need to do this)
             */
            toolkit vrvToolkit = new toolkit( false );
            vrvToolkit.setResourcePath( "../../data" );

            String s;
            String out;

            s = "@start:00000400004625-1.1.1\n";
            s = s + "@clef:C-3\n";
            s = s + "@keysig:xFCG\n";
            s = s + "@key:\n";
            s = s + "@timesig:c\n";
            s = s + "@data:" + "'4CCDE" + "\n";
            s = s + "@end:00000400004625-1.1.1\n";

            /* set the format to PAE and load the data */
            vrvToolkit.setInputFrom( "pae" );
            vrvToolkit.loadData( s );

            /* convert it and write it to the standard output */
            out = vrvToolkit.renderToSVG();
            logger.info( out );
        }
        catch ( Exception e )
        {
            logger.error( e.getMessage() );
        }
    }
}



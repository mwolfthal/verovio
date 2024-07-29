package test.rismch.verovio.mei;

import com.weichi.utils.logging.LogUtil;
import org.junit.jupiter.api.Test;
import org.rismch.verovio.LibraryLoader;
import org.rismch.verovio.VrvRuntimeException;
import org.rismch.verovio.generated.toolkit;
import org.slf4j.Logger;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class MeiTest
{
    private static final Logger logger;

    static
    {
        try
        {
            LogUtil.initLogger();
            logger = LogUtil.getLogger( MeiTest.class );
        }
        catch ( Exception e )
        {
            throw new VrvRuntimeException( e.getMessage() );
        }
    }

    @Test
    public void TestMei()
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

            String options = "{'adjustPageHeight': true, 'breaks': 'auto', 'scale': 50}";

            /* set some options */
            vrvToolkit.setOptions( options );

            String mei = "";
            try
            {
                mei = new String( Files.readAllBytes( Paths.get( "../../doc/importer.mei" ) ) );
            }
            catch ( IOException e )
            {
                System.out.println( "Could not read the mei file: " + e.getMessage() );
            }

            /* load the data */
            try
            {
                vrvToolkit.loadData( mei );
            }
            catch ( Exception e )
            {
                logger.error( "Could not load data: " + e.getMessage() );
            }

            /* render the data to svg  and write it */
            String svg;
            svg = vrvToolkit.renderToSVG();

            String path = "output.svg";
            Files.write( Paths.get( path ), svg.getBytes() );
            logger.info( "wrote svg file " + path );
        }
        catch ( Exception e )
        {
            logger.error( e.getMessage() );
        }
    }
}


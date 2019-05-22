package Utils;

import java.io.InputStream;
import java.util.Scanner;

public class ConvertStreamToString {
    public static String StreamToString(InputStream stream)
    {
        Scanner sc= new Scanner(stream).useDelimiter("\\A");
        return sc.hasNext() ? sc.next():"";
    }
}

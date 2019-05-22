
package Request;

import static Utils.ConvertStreamToString.StreamToString;
import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.nio.charset.Charset;

public class RequestBody {
    private InputStream body;
    
    public RequestBody(InputStream body)
    {
        this.body=body;
    }
    
    public RequestBody()
    {
        this.body=new ByteArrayInputStream(" ".getBytes(Charset.forName("UTF-8")));
    }
    
    public String getRequestBody()
    {
        return StreamToString(body);
    }
}

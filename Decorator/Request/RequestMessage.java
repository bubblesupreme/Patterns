
package Request;

import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.nio.charset.Charset;

public class RequestMessage {
    private InputStream msg;
    public RequestMessage(InputStream msg)
    {
        this.msg=msg;
    }
    public RequestMessage()
    {
        this.msg=new ByteArrayInputStream(" ".getBytes(Charset.forName("UTF-8")));
    }
}


package Response;

import java.io.InputStream;

public class OKResponse extends HttpResponse {
    public OKResponse(ResponseHeaders res_headers, InputStream body) {
        super(new ResponseLine("HTTP/1.1", 200, "OK"), res_headers, body);
    }
}

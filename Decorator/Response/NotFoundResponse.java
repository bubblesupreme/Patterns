
package Response;

import java.io.ByteArrayInputStream;

public class NotFoundResponse extends HttpResponse {
    public NotFoundResponse() {
        super(new ResponseLine("HTTP/1.1", 404, "Not Found"), 
                new ResponseHeaders(),
                new ByteArrayInputStream("404: Resource Not Found".getBytes()));
    }
}
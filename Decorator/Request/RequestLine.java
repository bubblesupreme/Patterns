
package Request;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URLDecoder;
import java.text.ParseException;
import java.util.HashMap;
import java.util.Map;


public class RequestLine {
    
    private String action;
    private String url;
    private Map<String, Object> parameters;
    private String protocol_version;
    
    public RequestLine(String line) throws ParseException, IOException
    {
        String[] requestLineItems = line.trim().split("\\s+");
        if (requestLineItems.length != 3) {
            throw new ParseException(String.format("Improperly formatted request line: %s", line),0);
        }
        parseRequestItems(requestLineItems);
    }
    
    private void parseRequestItems(String[] requestLineItems) 
            throws IOException, ParseException 
    {
        String[] requestUriItems = parseRequestUri(requestLineItems[1]);
        action = requestLineItems[0];
        url = requestUriItems[0];
        protocol_version = requestLineItems[2];
        parameters = UrlEncodedFormParse(
                new ByteArrayInputStream(requestUriItems[1].getBytes()), 
                requestUriItems[1].length());
    }
    
    private String[] parseRequestUri(String requestUri) 
    {
        String[] requestUriItems = new String[]{requestUri, ""};
        int questionMarkIndex = requestUri.indexOf("?");
        if (questionMarkIndex != -1) 
        {
            requestUriItems[0] = requestUri.substring(0, questionMarkIndex);
            requestUriItems[1] = requestUri.substring(questionMarkIndex + 1, 
                    requestUri.length());
        }
        return requestUriItems;
    }
    
    public Map<String, Object> UrlEncodedFormParse(InputStream inputStream, 
            int contentLength) throws IOException, ParseException 
    {
        byte[] b = new byte[contentLength];
        inputStream.read(b);
        String query = URLDecoder.decode(new String(b), "UTF-8");
        String[] stringParams = query.split("&");
        Map<String, Object> params = new HashMap<String, Object>();
        for (String stringParam : stringParams) {
            if (!query.equals("")) {
                String[] param = parseParam(stringParam);
                params.put(param[0], param[1]);
            }
        }
        return params;
    }
    
    private String[] parseParam(String query) throws ParseException {
        int index = query.indexOf("=");
        if (index == -1 || index == 0) {
            throw new ParseException("Improperly formatted query string",0);
        }
        return new String[]{query.substring(0, index), 
            query.substring(index + 1, query.length())};
    }
    
    public String getAction()
    {
        return action;
    }
    
    public String getUrl()
    {
        return url;
    }
    
    public Map<String, Object> getParameters()
    {
        return parameters;
    }
    
    public String getVersion()
    {
        return protocol_version;
    }
}

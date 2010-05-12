/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package Support;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

/**
 *
 * @author user
 */
public class IOObject {
public static void Save(Object o, String filenamesave)
    {
        //Save Map :
        String filename = filenamesave;

        FileOutputStream fos = null;
        ObjectOutputStream out = null;
        try
        {
            fos = new FileOutputStream(filename);
            out = new ObjectOutputStream(fos);
            out.writeObject(o);
            out.close();
        }
        catch (IOException ex)
        {
            ex.printStackTrace();
        }
    }

    public static Object Load(String filenameload)
    {
         //Load Map :
        Object o = null;
        String filename = filenameload;
        FileInputStream fis = null;
        ObjectInputStream in = null;
        try
        {
           fis = new FileInputStream(filename);
           in = new ObjectInputStream(fis);
           o = in.readObject();
           in.close();
        }
         catch (IOException ex)
        {
            ex.printStackTrace();
        }
        catch (ClassNotFoundException ex)
        {
            ex.printStackTrace();
        }

        return o;
    }
}

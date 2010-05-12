/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package Model.Map;

import java.awt.Point;
import java.io.Serializable;

/**
 *
 * @author user
 */
public class Map implements Serializable{
    public final static int RUMPUT = 0;
    public final static int LUMPUR = 1;
    public final static int AIR = 2;
    public final static int POHON = 3;
    public final static int CASTLE1 = 4;
    public final static int CASTLE2 = 5;
    public final static int CASTLE3 = 6;
    public final static int CASTLE4 = 7;
    private final static String[] contentString = {
        "rumput",
        "lumpur",
        "air",
        "pohon",
        "castle1",
        "castle2",
        "castle3",
        "castle4"
    };
    
    public final static int MAX_HEIGHT = 50;
    public final static int MIN_HEIGHT = 15;
    public final static int MAX_WIDTH = 50;
    public final static int MIN_WIDTH = 15;
    
    private int width;
    private int height;
    private int[][] Content;

    public Map() {
       this.width = MIN_WIDTH;
        this.height = MIN_HEIGHT;
       Content = new int[width][height];
       FillDefault();
    }

    public Map(int width, int height) {
        this.height = height;
        this.width = width;

        Content = new int[width][height];
        FillDefault();
    }

    private void FillDefault() {
        for (int i=0;i<width;++i) {
            for (int j=0;j<height;++j) {
                Content[i][j] = 0;
            }
        }
    }

    public void SetContent(int x, int y, int terrain) {
        Content[x][y] = terrain;
    }

    public int GetHeight() {
        return height;
    }

    public int GetWidth() {
        return width;
    }

    public Point GetCastlePosition(int number) {
        for (int i =0;i<width;++i) {
            for (int j=0;j<height;++j) {
                if (Content[i][j] == number) {
                    return new Point(i, j);
                }
            }
        }
        return null;
    }

    public int GetContent(int x, int y) {
        return Content[x][y];
    }

    public static String GetString(int contentnumber) {
        return contentString[contentnumber];
    }

    public static int GetContentNumber(String s) {
        for (int i=0;i<contentString.length;++i) {
            if (s.equals(contentString[i])) {
                return i;
            }
        }
        return -1;
    }

    public boolean IsCastleIn(int number) {
        if (GetCastlePosition(number)==null) {
            return false;
        }

        return true;
    }

    public boolean IsCastle(int number) {
        if (number >= CASTLE1 && number <= CASTLE4) {
            return true;
        }

        return false;
    }

    @Override
    public String toString() {
        String s = new String();
        for (int i=0;i<width;++i) {
            for (int j=0;j<height;++j) {
                s += Integer.toString(i);
                s += ",";
                s += Integer.toString(j);
                s += " : ";
                s += Integer.toString(Content[i][j]);
                s += "\n";
            }
        }
        return s;
    }


        
}


/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package Support;

import java.awt.Point;

/**
 *
 * @author user
 */
public class Converter {
    public static Point PointToGrid(int x, int y) {
        int X = x/ImageSupport.IMAGE_WIDTH;
        int Y = y/ImageSupport.IMAGE_HEIGHT;
        return new Point(X, Y);
    }

    public static Point PointToGrid(Point point) {
        return PointToGrid(point.x, point.y);
    }

    public static Point GridToPoint(int x, int y) {
        int X = x*ImageSupport.IMAGE_WIDTH;
        int Y = y*ImageSupport.IMAGE_HEIGHT;
        return new Point(X, Y);
    }

    public static Point GridToPoint(Point point) {
        return GridToPoint(point.x, point.y);
    }
}

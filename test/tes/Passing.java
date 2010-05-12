/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package tes;

/**
 *
 * @author user
 */
class Point {
    public Integer x;
    public Integer y;
    public Point(int x, int y) {
        this.x = new Integer(x);
        this.y = new Integer(y);
    }

    @Override
    public String toString() {
        return "X : "+x.toString()+"Y : "+y.toString();
    }

}

public class Passing {
    public static void main(String[] args) {
        Point a = new Point(5, 10);
        Point b = new Point(7, 9);
        System.out.println(a+" "+b);
        Swap(a, b);
        System.out.println(a+" "+b);
    }

    public static void Swap(Point a, Point b) {
        Point temp = new Point(b.x, b.y);
        b.x = new Integer(a.x);
        b.y  = new Integer(a.y);
        a.x = temp.x;
        a.y = temp.y;
    }
}

//
//  BenGRectangle.h
//  Programming Abstractions C++
//
//  Created by Ben Mills on 9/24/14.
//
//

#ifndef __Programming_Abstractions_C____BenGRectangle__
#define __Programming_Abstractions_C____BenGRectangle__

#include <string>
#include "vector.h"
#include "gtypes.h"

class BenGRectangle {
    
public:
    
    /*
     * Constructor: BenGRectangle
     * Usage: BenGRectangle empty;
     *        BenGRectangle r(x, y, width, height);
     * -----------------------------------------
     * Creates a <code>BenGRectangle</code> object with the specified components.
     * If these parameters are not supplied, the default constructor sets
     * these fields to 0.
     */
    
    BenGRectangle();
    BenGRectangle(double xc, double yc, double widthC, double heightC);
    
    /*
     * Method: getX
     * Usage: double x = r.getX();
     * ---------------------------
     * Returns the x component of the rectangle.
     */
    
    double getX() const;
    
    /*
     * Method: getY
     * Usage: double y = pt.getY();
     * ----------------------------
     * Returns the y component of the rectangle.
     */
    
    double getY() const;
    
    /*
     * Method: getWidth
     * Usage: double width = r.getWidth();
     * -----------------------------------
     * Returns the width component of the rectangle.
     */
    
    double getWidth() const;
    
    /*
     * Method: getHeight
     * Usage: double height = pt.getHeight();
     * --------------------------------------
     * Returns the height component of the rectangle.
     */
    
    double getHeight() const;
    
    /*
     * Method: isEmpty
     * Usage: if (r.isEmpty()) ...
     * ---------------------------
     * Returns <code>true</code> if the rectangle is empty.
     */
    
    bool isEmpty() const;
    
    /*
     * Method: contains
     * Usage: if (r.contains(pt)) ...
     *        if (r.contains(x, y)) ...
     * --------------------------------
     * Returns <code>true</code> if the rectangle contains the given point,
     * which may be specified either as a point or as distinct coordinates.
     */
    
    bool contains(double xc, double yc) const;
    
    /*
     * Method: toString
     * Usage: string str = r.toString();
     * ---------------------------------
     * Converts the <code>BenGRectangle</code> to a string in the form
     * <code>"(</code><i>x</i><code>,</code>&nbsp;<i>y</i><code>,</code>
     * <i>width</i><code>,</code>&nbsp;<i>height</i><code>)"</code>.
     */
    
    std::string toString() const;
    
    /* Private section */
    
    /**********************************************************************/
    /* Note: Everything below this point in this class is logically part  */
    /* of the implementation and should not be of interest to clients.    */
    /**********************************************************************/
    
private:
    
    /* Instance variables */
    
    double x;                       /* The x-coordinate of the rectangle */
    double y;                       /* The y-coordinate of the rectangle */
    double width = 0;                   /* The width of the rectangle        */
    double height = 0;                  /* The height of the rectangle       */
    
    /* Friend declarations */
    
    friend bool operator==(const BenGRectangle & r1, const BenGRectangle & r2);
    friend bool operator!=(const BenGRectangle & r1, const BenGRectangle & r2);
    friend int hashCode(const BenGRectangle & r);
    
};
#endif /* defined(__Programming_Abstractions_C____BenGRectangle__) */

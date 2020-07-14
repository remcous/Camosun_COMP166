<html>
<head>
<title>../common/include/graphics.h</title>
<link rel="stylesheet" type="text/css" href="cppdoc.css" />
</head>
<body>
<pre class=code>
<scan class=comment>/*
 * File: graphics.h
 * ----------------
 * This interface provides access to a simple graphics library that makes
 * it possible to draw lines, rectangles, ovals, arcs, polygons, images,
 * and strings on a graphical window.
 */
</scan>
#ifndef _graphics_h
#define _graphics_h

#include &lt;string&gt;
#include "gtypes.h"
#include "vector.h"

<a name="Function:initGraphics"><scan class=comment>/*
 * Function: initGraphics
 * Usage: initGraphics();
 *        initGraphics(width, height);
 * -----------------------------------
 * Creates the graphics window on the screen.  The first form creates a
 * window with a default size of 500x300; the second allows the client to
 * specify the size of the window.  The call to initGraphics must precede
 * any console output or calls to other functions in this interface.
 */
</scan>
void initGraphics();
void initGraphics(int width, int height);

<a name="Function:drawArc"><scan class=comment>/*
 * Function: drawArc
 * Usage: drawArc(bounds, start, sweep);
 *        drawArc(x, y, width, height, start, sweep);
 * --------------------------------------------------
 * Draws an elliptical arc inscribed in a rectangle.   The parameters x, y,
 * width, and height (or, equivalently, the GRectangle bounds) specify the
 * coordinates and dimensions of the bounding rectangle.  The start
 * parameter indicates the angle at which the arc begins and is measured in
 * degrees counterclockwise from the +x axis.  Thus, a start angle of 0
 * indicates an arc that begins along the line running eastward from the
 * center, a start angle of 135 begins along the line running northwest,
 * and a start angle of -90 begins along the line running south.  The sweep
 * parameter indicates the extent of the arc and is also measured in
 * degrees counterclockwise.  A sweep angle of 90 defines a quarter circle
 * extending counterclockwise from the start angle, and a sweep angle of
 * -180 defines a semicircle extending clockwise.
 */
</scan>
void drawArc(const GRectangle &amp; bounds, double start, double sweep);
void drawArc(double x, double y, double width, double height,
                                 double start, double sweep);

<a name="Function:fillArc"><scan class=comment>/*
 * Function: fillArc
 * Usage: fillArc(bounds, start, sweep);
 *        fillArc(x, y, width, height, start, sweep);
 * --------------------------------------------------
 * Fills a wedge-shaped area of an elliptical arc.  The parameters are
 * interpreted in the same way as those for drawArc.
 */
</scan>
void fillArc(const GRectangle &amp; bounds, double start, double sweep);
void fillArc(double x, double y, double width, double height,
                                 double start, double sweep);

<a name="Function:drawImage"><scan class=comment>/*
 * Function: drawImage
 * Usage: drawImage(filename, pt);
 *        drawImage(filename, x, y);
 *        drawImage(filename, bounds);
 *        drawImage(filename, x, y, width, height);
 * ------------------------------------------------
 * Draws the image from the specified file with its upper left corner at
 * the specified point.  The forms of the call that include the bounds
 * scale the image so that it fits inside the specified rectangle.
 */
</scan>
void drawImage(std::string filename, const GPoint &amp; pt);
void drawImage(std::string filename, double x, double y);
void drawImage(std::string filename, const GRectangle &amp; bounds);
void drawImage(std::string filename, double x, double y,
                                     double width, double height);

<a name="Function:getImageBounds"><scan class=comment>/*
 * Function: getImageBounds
 * Usage: GRectangle bounds = getImageBounds(filename);
 * ----------------------------------------------------
 * Returns the bounds of the image contained in the specified file.  Only
 * the width and height components of the rectangle are of interest; the x
 * and y components are always 0.
 */
</scan>
GRectangle getImageBounds(std::string filename);

<a name="Function:drawLine"><scan class=comment>/*
 * Function: drawLine
 * Usage: drawLine(p0, p1);
 *        drawLine(x0, y0, x1, y1);
 * --------------------------------
 * Draws a line connecting the specified points.
 */
</scan>
void drawLine(const GPoint &amp; p0, const GPoint &amp; p1);
void drawLine(double x0, double y0, double x1, double y1);

<a name="Function:drawPolarLine"><scan class=comment>/*
 * Function: drawPolarLine
 * Usage: GPoint p1 = drawPolarLine(p0, r, theta);
 *        GPoint p1 = drawPolarLine(x0, y0, r, theta);
 * ---------------------------------------------------
 * Draws a line of length r in the direction theta from the initial point. 
 * The angle theta is measured in degrees counterclockwise from the +x
 * axis.  The function returns the end point of the line.
 */
</scan>
GPoint drawPolarLine(const GPoint &amp; p0, double r, double theta);
GPoint drawPolarLine(double x0, double y0, double r, double theta);

<a name="Function:drawOval"><scan class=comment>/*
 * Function: drawOval
 * Usage: drawOval(bounds);
 *        drawOval(x, y, width, height);
 * -------------------------------------
 * Draws the frame of a oval with the specified bounds.
 */
</scan>
void drawOval(const GRectangle &amp; bounds);
void drawOval(double x, double y, double width, double height);

<a name="Function:fillOval"><scan class=comment>/*
 * Function: fillOval
 * Usage: fillOval(bounds);
 *        fillOval(x, y, width, height);
 * -------------------------------------
 * Fills the frame of a oval with the specified bounds.
 */
</scan>
void fillOval(const GRectangle &amp; bounds);
void fillOval(double x, double y, double width, double height);

<a name="Function:drawRect"><scan class=comment>/*
 * Function: drawRect
 * Usage: drawRect(bounds);
 *        drawRect(x, y, width, height);
 * -------------------------------------
 * Draws the frame of a rectangle with the specified bounds.
 */
</scan>
void drawRect(const GRectangle &amp; bounds);
void drawRect(double x, double y, double width, double height);

<a name="Function:fillRect"><scan class=comment>/*
 * Function: fillRect
 * Usage: fillRect(bounds);
 *        fillRect(x, y, width, height);
 * -------------------------------------
 * Fills the frame of a rectangle with the specified bounds.
 */
</scan>
void fillRect(const GRectangle &amp; bounds);
void fillRect(double x, double y, double width, double height);

<a name="Function:drawPolygon"><scan class=comment>/*
 * Function: drawPolygon
 * Usage: drawPolygon(polygon);
 *        drawPolygon(polygon, pt);
 *        drawPolygon(polygon, x, y);
 * ----------------------------------
 * Draws the outline of the specified polygon.  The optional pt or x and y
 * parameters shift the origin of the polygon to the specified point.
 */
</scan>
void drawPolygon(const Vector&lt;GPoint&gt; &amp; polygon);
void drawPolygon(const Vector&lt;GPoint&gt; &amp; polygon, const GPoint &amp; pt);
void drawPolygon(const Vector&lt;GPoint&gt; &amp; polygon, double x, double y);

<a name="Function:fillPolygon"><scan class=comment>/*
 * Function: fillPolygon
 * Usage: fillPolygon(polygon);
 *        fillPolygon(polygon, pt);
 *        fillPolygon(polygon, x, y);
 * ----------------------------------
 * Fills the frame of the specified polygon.  The optional pt or x and y
 * parameters shift the origin of the polygon to the specified point.
 */
</scan>
void fillPolygon(const Vector&lt;GPoint&gt; &amp; polygon);
void fillPolygon(const Vector&lt;GPoint&gt; &amp; polygon, const GPoint &amp; pt);
void fillPolygon(const Vector&lt;GPoint&gt; &amp; polygon, double x, double y);

<a name="Function:drawString"><scan class=comment>/*
 * Function: drawString
 * Usage: drawString(str, pt);
 *        drawString(str, x, y);
 * -----------------------------
 * Draws the string str so that its baseline origin appears at the
 * specified point.  The text appears in the current font and color.
 */
</scan>
void drawString(std::string str, const GPoint &amp; pt);
void drawString(std::string str, double x, double y);

<a name="Function:getStringWidth"><scan class=comment>/*
 * Function: getStringWidth
 * Usage: double width = getStringWidth(str);
 * ------------------------------------------
 * Returns the width of the string str when displayed in the current font.
 */
</scan>
double getStringWidth(std::string str);

<a name="Function:setFont"><scan class=comment>/*
 * Function: setFont
 * Usage: setFont(font);
 * ---------------------
 * Sets a new font.  The font parameter is a string in the form
 * family-style-size.  In this string, family is the name of the font
 * family; style is either missing (indicating a plain font) or one of the
 * strings Bold, Italic, or BoldItalic; and size is an integer indicating
 * the point size.  If any of these components is specified as an asterisk,
 * the existing value is retained.  The font parameter can also be a
 * sequence of such specifications separated by semicolons, in which the
 * first available font on the system is used.
 */
</scan>
void setFont(std::string font);

<a name="Function:getFont"><scan class=comment>/*
 * Function: getFont
 * Usage: string font = getFont();
 * -------------------------------
 * Returns the current font.
 */
</scan>
std::string getFont();

<a name="Function:setColor"><scan class=comment>/*
 * Function: setColor
 * Usage: setColor(color);
 * -----------------------
 * Sets the color used for drawing.  The color parameter is usually one of
 * the predefined color names from Java:
 *
 *    BLACK,
 *    BLUE,
 *    CYAN,
 *    DARK_GRAY,
 *    GRAY,
 *    GREEN,
 *    LIGHT_GRAY,
 *    MAGENTA,
 *    ORANGE,
 *    PINK,
 *    RED,
 *    WHITE, or
 *    YELLOW.
 *
 * The case of the individual letters in the color name is ignored, as are
 * spaces and underscores, so that the Java color DARK_GRAY could be
 * written as "Dark Gray".
 *
 * The color can also be specified as a string in the form "#rrggbb" where
 * rr, gg, and bb are pairs of hexadecimal digits indicating the red,
 * green, and blue components of the color.
 */
</scan>
void setColor(std::string color);

<a name="Function:getColor"><scan class=comment>/*
 * Function: getColor
 * Usage: string color = getColor();
 * ---------------------------------
 * Returns the current color as a string in the form "#rrggbb".  In this
 * string, the values rr, gg, and bb are two-digit hexadecimal values
 * representing the red, green, and blue components of the color,
 * respectively.
 */
</scan>
std::string getColor();

<a name="Function:saveGraphicsState"><scan class=comment>/*
 * Function: saveGraphicsState
 * Usage: saveGraphicsState();
 * ---------------------------
 * Saves the state of the graphics context.  This function is used in
 * conjunction with restoreGraphicsState() to avoid changing the state set
 * up by the client.
 */
</scan>
void saveGraphicsState();

<a name="Function:restoreGraphicsState"><scan class=comment>/*
 * Function: restoreGraphicsState
 * Usage: restoreGraphicsState();
 * ------------------------------
 * Restores the graphics state from the most recent call to
 * saveGraphicsState().
 */
</scan>
void restoreGraphicsState();

<a name="Function:getWindowWidth"><scan class=comment>/*
 * Function: getWindowWidth
 * Usage: double width = getWindowWidth();
 * ---------------------------------------
 * Returns the width of the graphics window in pixels.
 */
</scan>
double getWindowWidth();

<a name="Function:getWindowHeight"><scan class=comment>/*
 * Function: getWindowHeight
 * Usage: double height = getWindowHeight();
 * -----------------------------------------
 * Returns the height of the graphics window in pixels.
 */
</scan>
double getWindowHeight();

<a name="Function:repaint"><scan class=comment>/*
 * Function: repaint
 * Usage: repaint();
 * -----------------
 * Issues a request to update the graphics window.  This function is called
 * automatically when the program pauses, waits for an event, waits for
 * user input on the console, or terminates.  As a result, most clients
 * will never need to call repaint explicitly.
 */
</scan>
void repaint();

<a name="Function:pause"><scan class=comment>/*
 * Function: pause
 * Usage: pause(milliseconds);
 * ---------------------------
 * Pauses for the indicated number of milliseconds.  This function is
 * useful for animation where the motion would otherwise be too fast.
 */
</scan>
void pause(double milliseconds);

<a name="Function:waitForClick"><scan class=comment>/*
 * Function: waitForClick
 * Usage: waitForClick();
 * ----------------------
 * Waits for a mouse click to occur anywhere in the window.
 */
</scan>
void waitForClick();

<a name="Function:setWindowTitle"><scan class=comment>/*
 * Function: setWindowTitle
 * Usage: setWindowTitle(title);
 * -----------------------------
 * Sets the title of the primary graphics window.
 */
</scan>
void setWindowTitle(std::string title);

<a name="Function:getWindowTitle"><scan class=comment>/*
 * Function: getWindowTitle
 * Usage: string title = getWindowTitle();
 * ---------------------------------------
 * Returns the title of the primary graphics window.
 */
</scan>
std::string getWindowTitle();

<a name="Function:exitGraphics"><scan class=comment>/*
 * Function: exitGraphics
 * Usage: exitGraphics();
 * ----------------------
 * Closes the graphics window and exits from the application without
 * waiting for any additional user interaction.
 */
</scan>
void exitGraphics();

#include "console.h"
#include "private/main.h"

#endif
</pre>
</body>
</html>

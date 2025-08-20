class Point {
    private:
        int xCoordinate;
        int yCoordinate;

    public:
        Point();
        Point(int x, int y);
        Point(Point* point);
        ~Point() = default;

        int getX();
        int setX(int x);
        int getY();
        int setY(int y);

};
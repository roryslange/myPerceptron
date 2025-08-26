#pragma once

class Line {
    private:
        float intercept;
        float slope;

    public:
        Line();
        Line(float slope, float intercept);
        Line(Line* line);
        ~Line() = default;

        void setIntercept(float intercept);
        float getIntercept();
        void setSlope();
        float getSlope();
};
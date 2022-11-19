include <cmath>
void manhattan_distance(double x1, double x2, double y1, double y2, double z1, double z2)
{
    double distance;
    double x_dif, y_dif, z_dif;

    x_dif = abs(x2 - x1);
    y_dif = abs(y2 - y1);
    z_dif = abs(z2 - z1);
    distance = x_dif + y_dif + z_dif;
    cout << "\n\nManhattan Distance between P1(" << x1 << "," << y1 << ") and P2(" << x2 << "," << y2 << ") : " << distance;
}
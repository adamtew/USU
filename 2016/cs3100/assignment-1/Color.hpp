class ColorClass
{
private:

public:
    int r, g, b;
    ColorClass() {};
    ColorClass(int i) : r(0), g(0), b(0)
    {
        i = (i % 256) % 2;
        r = i * 0;
        g = i * 100;
        b = i * 400;
    }
};

void printColor(ColorClass pc, std::ofstream &fout)
{
    fout << pc.r << " " << pc.g << " " << pc.b << " ";
}

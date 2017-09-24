class ColorClass
{
private:

public:
    int r, g, b;
    ColorClass() {};
    ColorClass(int i) : r(0), g(0), b(0)
    {
        i = (i % 256) % 2;
        r = i * rand() % 256 + 1;
        g = i * rand() % 256 + 1;
        b = i * rand() % 256 + 1;
    }
};

void printColor(ColorClass pc, std::ofstream &fout)
{
    fout << pc.r << " " << pc.g << " " << pc.b << " ";
}

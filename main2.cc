#include <algorithm>

#include <cstdio>


class FoxPlayingGame {
public:
  double theMax(int nA, int nB, int paramA, int paramB);

private:
  double sum(int nA, int nB, int paramA, int paramB);
};

double FoxPlayingGame::theMax(int nA, int nB, int paramA, int paramB)
{
  double max = nA * paramA / 1000.0;

  for (int i = 1; i <= nB; i ++) {
    double x = nA * paramA / 1000.0;

    for (int j = 0; j < i; j ++)
      x *= paramB / 1000.0;

    max = std::max(x, max);
  }
  return max;
}


int main(int argc, char** argv)
{
  int nA, nB, paramA, paramB;

  while (fscanf(stdin, "%d %d %d %d", &nA, &nB, &paramA, &paramB) == 4)
    fprintf(stdout, "%.1f\n", FoxPlayingGame().theMax(nA, nB, paramA, paramB));
}

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
  return sum(nA, nB, paramA, paramB);
}

double FoxPlayingGame::sum(int nA, int nB, int paramA, int paramB)
{
  if (nB == 0) {
    return nA * paramA / 1000.0;
  }
  else if (nA == 0) {
    return 0.0;
  }
  else {
    return std::max(sum(nA - 1, nB,     paramA, paramB) + paramA / 1000.0,
		    sum(nA,     nB - 1, paramA, paramB) * paramB / 1000.0);
  }
}


int main(int argc, char** argv)
{
  int nA, nB, paramA, paramB;

  while (fscanf(stdin, "%d %d %d %d", &nA, &nB, &paramA, &paramB) == 4)
    fprintf(stdout, "%.1f\n", FoxPlayingGame().theMax(nA, nB, paramA, paramB));
}

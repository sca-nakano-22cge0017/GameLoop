#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

int main() {
  const int MAX_SUCCESS = 3;
  const int MAX_WRONG = 3;
  
  vector<string> letters; //お題文字
  letters.push_back("a");
  letters.push_back("i");
  letters.push_back("u");
  letters.push_back("e");
  letters.push_back("o");

  vector<string> mine; //使用禁止文字
  mine.push_back("k");
  mine.push_back("s");
  mine.push_back("t");
  mine.push_back("n");
  mine.push_back("h");

  srand(static_cast<unsigned int>(time(0)));
  random_shuffle(letters.begin(),letters.end());
  random_shuffle(mine.begin(), mine.end());

  const string LETTERS = letters[0];
  const string MINE = mine[0];
  int success = 0;
  int wrong = 0;
  
  cout << "\nお題で出された文字から始まる三文字の単語を答えよう！\nただし「" << mine[0] <<"」の文字を使うのは禁止だ！\n３回成功でゲームクリア！３回禁止された文字を使ったり、お題の文字から始まっていなかったりするとゲームオーバーになるぞ！" << endl;
  cout << "\nお題：" << letters[0] << endl;

  while ((wrong < MAX_WRONG) && (success < MAX_SUCCESS))
    {
      cout << "ゲームクリアまであと" << (MAX_SUCCESS - success) << "回成功\nゲームオーバーまであと" << (MAX_WRONG - wrong) << "回失敗" << endl;

      string Answer;
      cout << "\nあなたの解答：";
      cin >> Answer;

      bool miss = false;
      if ((Answer.substr(0, 1) == MINE) || (Answer.substr(1, 1) == MINE) || (Answer.substr(2, 1) == MINE) || (Answer.substr(0, 1) != LETTERS))
      {
        miss = true;
      }

      if ((Answer.substr(0, 1) == LETTERS) && (miss == false) && (Answer.size() == 3))
      {
        cout << "\n正解！\n" << endl;
        ++success;
      }
      if ((miss == true) && (Answer.size() == 3))
      {
        cout << "\n失敗！\n" << endl;
        ++wrong;
      }

      if (Answer.size() != 3)
      {
        cout << "\n三文字の単語を答えてください\n" << endl; 
      }
    }

  if (success == MAX_SUCCESS)
  {
    cout <<"\nゲームクリア！\nコングラチュレーション！\n" << endl;
  }
  if (wrong == MAX_WRONG)
  {
    cout <<"\nゲームオーバー・・・\n" << endl;
  }
}
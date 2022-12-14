#include <cp/cp.hpp>

/**
 * @brief Represents the scorecard of a team in the given format.
 *
 */
struct scorecard
{
  cp::string team_name;
  cp::list_string batsmen_names;
  cp::list_int batsmen_scores;
};

/**
 * @brief Read the scorecard from the given file and return the created scorecard.
 *
 * You can assume that the given file is in the proper format: The first line is the team's name followed by pairs of lines where the first in each pair is a cp::string, the name of the player, and the second is a non-negative integer, the runs scored by that player. There will always be `2k+1` lines in the file where `k` is the number of players who scored in that team. (Note, there is no blank line at the end.)
 *
 * It is not guaranteed, however, that it lists between 2 and 11 batsmen (both inclusive). Your function should check for this, and if the input file violates this, no report should be produced.
 *
 */
scorecard *read_scorecard(cp::string file_name)
{
  cp::input_file file = cp::input_file(file_name);
  scorecard *sc = new scorecard();
  sc->team_name = file.read<cp::string>();
  int i = 0;
  while (cp::not_op(file.eof()))
  {
    sc->batsmen_names.insert_at(i, file.read<cp::string>());
    sc->batsmen_scores.insert_at(i, file.read_double());
    i++;
  }
  file.close();
  return sc;
}

/**
 * @brief Calculates the total score of a team given its scoreboard
 */
int total_score(scorecard *sc)
{
  int total = 0;
  for (int i = 0; i < sc->batsmen_scores.size(); i++)
  {
    total += sc->batsmen_scores[i];
  }
  return total;
}

/**
 * @brief Calculates the highest individual score from a team given its scoreboard
 */
int highest_score(scorecard *sc)
{
  int score = sc->batsmen_scores[0];
  for (int i = 0; i < sc->batsmen_scores.size(); i++)
  {
    if (sc->batsmen_scores[i] > score)
    {
      score = sc->batsmen_scores[i];
    }
  }
  return score;
}

/**
 * @brief Checks if a scoreboard is valid ie, that it lists between 2 and 11 batsmen (both inclusive)
 */
bool is_valid_scorecard(scorecard *sc)
{
  int size = sc->batsmen_names.size();
  if (cp::and_op(size <= 11, size >= 2))
  {
    return true;
  }
  return false;
}

/**
 * @brief Returns the report of the match as a string in the following format:
 *
 * <WinningTeamName> (<WinningTeamTotal) beats <LosingTeamName> (LosingTeamTotal)
 * The highest scorer(s): <HighestScorerName> (<HighestScorerRuns>)[, <HighestScorerName> (<HighestScorerRuns>)...]
 *
 * If the match is a tie, the first line of the report reads:
 *
 * The match is tied at (<runs>)
 *
 * If there are more than one batsmen with the highest score, the second line lists ALL of them, separated by commas.
 *
 */
cp::string report(scorecard *t1, scorecard *t2)
{
  cp::string report = cp::EMPTY_STR;
  if (cp::not_op(cp::and_op(is_valid_scorecard(t1), is_valid_scorecard(t2))))
  {
    report = "Incoming file(s) is not a valid scorecard";
    return report;
  }

  int total_score_t1 = total_score(t1);
  int total_score_t2 = total_score(t2);
  if (total_score_t1 > total_score_t2)
  {
    report = t1->team_name + " (" + cp::to_string(total_score_t1) + ") beats " + t2->team_name + " (" + cp::to_string(total_score_t2) + ")\n";
  }
  else if (total_score_t1 < total_score_t2)
  {
    report = t2->team_name + " (" + cp::to_string(total_score_t2) + ") beats " + t1->team_name + " (" + cp::to_string(total_score_t1) + ")\n";
  }
  else
  {
    report = cp::string("The match is tied at (") + cp::to_string(total_score_t1) + ")\n";
  }

  int highest_score_t1 = highest_score(t1);
  int highest_score_t2 = highest_score(t2);
  int highest_score;

  if (highest_score_t1 > highest_score_t2)
  {
    highest_score = highest_score_t1;
  }
  else
  {
    highest_score = highest_score_t2;
  }

  cp::list_string highest_score_batsmen;
  int count = 0;
  for (int i = 0; i < t1->batsmen_scores.size(); i++)
  {
    if (t1->batsmen_scores[i] == highest_score)
    {
      highest_score_batsmen.insert_at(count, t1->batsmen_names[i]);
      count++;
    }
  }
  for (int i = 0; i < t2->batsmen_scores.size(); i++)
  {
    if (t2->batsmen_scores[i] == highest_score)
    {
      highest_score_batsmen.insert_at(count, t2->batsmen_names[i]);
      count++;
    }
  }
  report = report + cp::string("The highest scorer(s): ");
  for (int i = 0; i < highest_score_batsmen.size(); i++)
  {
    report = report + highest_score_batsmen[i] + " (" + cp::to_string(highest_score) + ")";
    if (i < highest_score_batsmen.size() - 1)
    {
      report = report + ", ";
    }
  }

  return report;
}

int main()
{
  scorecard *team1 = read_scorecard("team1.txt");

  scorecard *team2 = read_scorecard("team2.txt");

  cp::println(report(team1, team2));

  return 0;
}
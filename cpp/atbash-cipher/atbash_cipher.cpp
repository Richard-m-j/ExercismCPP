#include "atbash_cipher.h"

namespace atbash_cipher
{
    vector<int> round_down_scores(vector<double> student_scores)
    {
        vector<int> rounded_scores;
        for (int i = 0; i < student_scores.size(); i++)
            rounded_scores.push_back(static_cast<int>(student_scores[i]));

        return rounded_scores;
    }
    int count_failed_students(vector<double> student_scores)
    {
        vector <int>rounded_scores = round_down_scores(student_scores);
        int failed_students = 0;
        for (int i = 0; i < rounded_scores.size(); i++)
            if (rounded_scores[i] < 48)
                failed_students++;
        return failed_students;
    }
    vector<int> above_threshold(vector<double> student_scores, int threshold)
    {
        vector<int> rounded_scores = round_down_scores(student_scores);
        vector<int> above_threshold;
        for (int i = 0; i < rounded_scores.size(); i++)
            if (student_scores[i] >= 48)
                above_threshold.push_back(student_scores[i]);
        return above_threshold;
    }
    int* letter_grade(int score)
    {
        int lower_bounds[4];
        lower_bounds[0] = 48+1;
        lower_bounds[1] = lower_bounds[0] + score / 4;
        lower_bounds[2] = lower_bounds[1] + score / 4;
        lower_bounds[3] = lower_bounds[2] + score / 4;
        return lower_bounds;
    }
    vector <string> student_ranking(vector<int> student_scores, vector<string> student_names)
    {
        vector <string> student_ranking;
        for(int i=0;i<student_scores.size();i++)
            student_ranking.push_back(to_string(i + 1)+ student_names[i]+ to_string(student_scores[i]));
    }
    string perfect_score(vector<int> student_scores, vector<string> student_names+)

} // namespace atbash_cipher

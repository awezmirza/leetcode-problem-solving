class Solution {
public:

    long long findAbsDiff(string str1, string str2) {
        return abs(stoll(str1) - stoll(str2));
    }

    string nearestPalindromic(string n) {
        int len = n.size();
        if (len == 1) {
            return n == "0" ? "1" : to_string(stoi(n) - 1);
        }
        if (n == "11" || n == "10") {
            return "9";
        }
        string firstHalf = n.substr(0, len / 2);
        string secondHalf = n.substr(len / 2);

        if (firstHalf.length() != secondHalf.length()) {
            string firstHalfRev = firstHalf;
            reverse(firstHalfRev.begin(), firstHalfRev.end());
            if (secondHalf[0] != '0' && secondHalf[0] != '9') {
                string secondHalfContestant1 = secondHalf[0] + firstHalfRev;
                string secondHalfContestant2 = to_string(secondHalf[0] - '0' - 1) + firstHalfRev;
                string secondHalfContestant3 = to_string(secondHalf[0] - '0' + 1) + firstHalfRev;

                long long absDiffCont1 = findAbsDiff(secondHalf, secondHalfContestant1);
                long long absDiffCont2 = findAbsDiff(secondHalf, secondHalfContestant2);
                long long absDiffCont3 = findAbsDiff(secondHalf, secondHalfContestant3);

                if (absDiffCont1 == 0) {
                    if (absDiffCont3 < absDiffCont2) {
                        return firstHalf + secondHalfContestant3;
                    } else {
                        return firstHalf + secondHalfContestant2;
                    }
                } else {
                    long long ansCont = min(absDiffCont1, min(absDiffCont2, absDiffCont3));
                    if (ansCont == absDiffCont2) {
                        return firstHalf + secondHalfContestant2;
                    } else if (ansCont == absDiffCont1) {
                        return firstHalf + secondHalfContestant1;
                    } else {
                        return firstHalf + secondHalfContestant3;
                    }
                }
                

            } else {
                if (secondHalf[0] == '9') {
                    string secondHalfContestant1 = secondHalf[0] + firstHalfRev;
                    string secondHalfContestant2 = to_string(secondHalf[0] - '0' - 1) + firstHalfRev;
                    string secondHalfContestant3 = "0";
                    string firstHalfInc = to_string(stoll(firstHalf) + 1);

                    int firstSize = firstHalf.size();
                    for (int i = firstSize - 1; i >= 0; i--) {
                        secondHalfContestant3.push_back(firstHalfInc[i]);
                    }

                    long long absDiffCont1 = findAbsDiff(secondHalf, secondHalfContestant1);
                    long long absDiffCont2 = findAbsDiff(secondHalf, secondHalfContestant2);
                    long long absDiffCont3 = findAbsDiff(firstHalf + secondHalf, firstHalfInc + secondHalfContestant3);

                    if (absDiffCont1 == 0) {
                        if (absDiffCont3 < absDiffCont2) {
                            return firstHalfInc + secondHalfContestant3;
                        } else {
                            return firstHalf + secondHalfContestant2;
                        }
                    } else {
                        long long ansCont = min(absDiffCont1, min(absDiffCont2, absDiffCont3));
                        if (ansCont == absDiffCont2) {
                            return firstHalf + secondHalfContestant2;
                        } else if (ansCont == absDiffCont1) {
                            return firstHalf + secondHalfContestant1;
                        } else {
                            return firstHalfInc + secondHalfContestant3;
                        }
                    }
                } else {
                    string secondHalfContestant1 = secondHalf[0] + firstHalfRev;
                    string secondHalfContestant3 = to_string(secondHalf[0] - '0' + 1) + firstHalfRev;
                    string secondHalfContestant2 = "9";
                    string firstHalfDec = to_string(stoll(firstHalf) - 1);
                    
                    if (stoll(firstHalf) - 1 == 0) {
                        int firstSize = firstHalf.size();
                        secondHalfContestant2 = "";
                        for (int i = 2 * firstSize - 1; i >= 0; i--) {
                            secondHalfContestant2.push_back('9');
                        }
                        firstHalfDec = "";
                    } else if (firstHalf.size() != firstHalfDec.size()) {
                        firstHalfDec = firstHalfDec + "9";
                        string revDecFirst = firstHalfDec;
                        reverse(revDecFirst.begin(), revDecFirst.end());
                        secondHalfContestant2 = revDecFirst;
                        // cout<<
                        // cout<<firstHalfDec + secondHalfContestant2; 
                    } else {                            
                        string revDecFirst = firstHalfDec;
                        reverse(revDecFirst.begin(), revDecFirst.end());
                        secondHalfContestant2 += revDecFirst;
                    }

                    long long absDiffCont1 = findAbsDiff(secondHalf, secondHalfContestant1);
                    long long absDiffCont2 = findAbsDiff(firstHalf + secondHalf, firstHalfDec + secondHalfContestant2);
                    long long absDiffCont3 = findAbsDiff(secondHalf, secondHalfContestant3);

                    if (absDiffCont1 == 0) {
                        if (absDiffCont3 < absDiffCont2) {
                            return firstHalf + secondHalfContestant3;
                        } else {
                            return firstHalfDec + secondHalfContestant2;
                        }
                    } else {
                        long long ansCont = min(absDiffCont1, min(absDiffCont2, absDiffCont3));
                        if (ansCont == absDiffCont2) {
                            return firstHalfDec + secondHalfContestant2;
                        } else if (ansCont == absDiffCont1) {
                            return firstHalf + secondHalfContestant1;
                        } else {
                            return firstHalf + secondHalfContestant3;
                        }
                    }
                }
            }
        } else {
            
            string firstHalfRev = firstHalf;
            reverse(firstHalfRev.begin(), firstHalfRev.end());
            if (firstHalf.back() != '0' && firstHalf.back() != '9') {

                string contestant1 = firstHalf + firstHalfRev;

                string dec = to_string(stoll(firstHalf) - 1);
                string temp = dec;
                reverse(temp.begin(), temp.end());
                string contestant2 = dec + temp;

                string inc = to_string(stoll(firstHalf) + 1);
                temp = inc;
                reverse(temp.begin(), temp.end());
                string contestant3 = inc + temp;

                long long absDiffCont1 = findAbsDiff(n, contestant1);
                long long absDiffCont2 = findAbsDiff(n, contestant2);
                long long absDiffCont3 = findAbsDiff(n, contestant3);

                if (absDiffCont1 == 0) {
                    if (absDiffCont3 < absDiffCont2) {
                        return contestant3;
                    } else {
                        return contestant2;
                    }
                } else {
                    long long ansCont = min(absDiffCont1, min(absDiffCont2, absDiffCont3));
                    if (ansCont == absDiffCont2) {
                        return contestant2;
                    } else if (ansCont == absDiffCont1) {
                        return contestant1;
                    } else {
                        return contestant3;
                    }
                }
                

            } else {
                if (firstHalf.back() == '9') {

                    string contestant1 = firstHalf + firstHalfRev;

                    string dec = to_string(stoll(firstHalf) - 1);
                    string temp = dec;
                    reverse(temp.begin(), temp.end());
                    string contestant2 = dec + temp;

                    string inc = to_string(stoll(firstHalf) + 1);
                    int size = secondHalf.size();
                    for (int i = size - 1; i >= 0; i--) {
                        inc.push_back(inc[i]);
                    }
                    string contestant3 = inc;

                    long long absDiffCont1 = findAbsDiff(n, contestant1);
                    long long absDiffCont2 = findAbsDiff(n, contestant2);
                    long long absDiffCont3 = findAbsDiff(n, contestant3);

                    if (absDiffCont1 == 0) {
                        if (absDiffCont3 < absDiffCont2) {
                            return contestant3;
                        } else {
                            return contestant2;
                        }
                    } else {
                        long long ansCont = min(absDiffCont1, min(absDiffCont2, absDiffCont3));
                        if (ansCont == absDiffCont2) {
                            return contestant2;
                        } else if (ansCont == absDiffCont1) {
                            return contestant1;
                        } else {
                            return contestant3;
                        }
                    }
                } else {
                    string contestant1 = firstHalf + firstHalfRev;

                    string dec = to_string(stoll(firstHalf) - 1);
                    if (firstHalf.size() != dec.size()) {
                        int len = secondHalf.size();
                        for (int i = 0; i < len; i++) {
                            dec.push_back('9');
                        }
                    } else {
                        string temp = dec;
                        reverse(temp.begin(), temp.end());
                        dec += temp;
                    }
                    string contestant2 = dec;

                    string inc = to_string(stoll(firstHalf) + 1);
                    string temp = inc;
                    reverse(temp.begin(), temp.end());
                    string contestant3 = inc + temp;

                    long long absDiffCont1 = findAbsDiff(n, contestant1);
                    long long absDiffCont2 = findAbsDiff(n, contestant2);
                    long long absDiffCont3 = findAbsDiff(n, contestant3);

                    if (absDiffCont1 == 0) {
                        if (absDiffCont3 < absDiffCont2) {
                            return contestant3;
                        } else {
                            return contestant2;
                        }
                    } else {
                        long long ansCont = min(absDiffCont1, min(absDiffCont2, absDiffCont3));
                        if (ansCont == absDiffCont2) {
                            return contestant2;
                        } else if (ansCont == absDiffCont1) {
                            return contestant1;
                        } else {
                            return contestant3;
                        }
                    }
                }
            }
        }
        return firstHalf;
    }
};
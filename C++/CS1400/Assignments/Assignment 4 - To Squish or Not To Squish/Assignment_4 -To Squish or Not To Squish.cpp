#include <iostream>

using namespace std;

int main(){
    char c;
    cout << "To squish or not to squish?\n\n";
    cout << "Is it freaking you out?\n>";
    cin >> c;

    if (c == 'y'||c=='Y'){
        cout << "Bug are squished.\n>";
    }else{
        cout << "Does it bite or suck blood?\n>";
        cin >> c;
        if (c == 'y' || c == 'Y'){
            cout << "Bug are squished.\n>";
        }else{
            cout << "How many legs?\n>";
            int a;
            cin >> a;
            if (a >= 5 && a <= 10){
                cout << "Bug are squished.\n>";
            }else{
                cout << "Does it hiss?\n>";
                cin >> c;
                if (c == 'y' || c == 'Y'){
                    cout << "Bug are squished.\n>";
                }else{
                    cout << "Is it a ladybug or a praying mantis?\n>";
                    cin >> c;
                    if (c == 'n' || c == 'N'){
                        cout << "Bug are squished.\n>";
                    }else{
                        cout << "Do you believe in reincarnation?\n";
                        cin >> c;
                        if(c == 'n' || c == 'N'){
                            cout << "Bug are squished.\n";
                        }else{
                            cout << "The bug lives another day.";
                        }
                    }
                }
            }
        }
    }

    return 0;

}
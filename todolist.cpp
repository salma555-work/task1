#include <iostream>


using namespace std;

void showtask(string tasks[], bool completed[], int s) {
    for (int i = 0; i < s; ++i) {
        cout << (i + 1) << ". ";
        if (completed[i]) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }
        cout << tasks[i] << endl;
    }
}

int main() {
    string tasks[100] = {""};
    bool completed[100] = {false}; // Tableau pour suivre l'état de complétion des tâches
    int s = 0;
    int option = -100;

    while (option != 4) {
        cout << "To do list " << endl;
        cout << "1. Ajouter une tache " << endl;
        cout << "2. Voir les taches " << endl;
        cout << "3. Cocher une tache comme complete " << endl;
        cout << "4. Quitter" << endl;
        cin >> option;
        
        switch (option) {
            case 1:
                if (s > 99) {
                    cout << "La liste est pleine" << endl;
                } else {
                    cout << "Ecrivez une nouvelle tache :";
                    cin.ignore();
                    getline(cin, tasks[s]);
                    s++;
                }
                break;
            case 2:
                showtask(tasks, completed, s);
                break;
            case 3:
                int index;
                cout << "Entrez l'index de la tache a cocher comme complete: ";
                cin >> index;
                if (index >= 1 && index <= s) {
                    completed[index - 1] = true;
                    cout << "Tache cochee comme complete!" << endl;
                } else {
                    cout << "Index invalide!" << endl;
                }
                break;
            case 4:
                cout << "Au revoir!" << endl;
                break;
            default:
                cout << "Choix invalide. Veuillez reessayer." << endl;
        }
    }

    return 0;
}

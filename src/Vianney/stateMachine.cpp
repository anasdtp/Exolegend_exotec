// #include <iostream>
// #include <string>

// using namespace std;

// // Définition de la classe de la machine à états
// class StateMachine
// {
// public:
//     // Énumération des états possibles
//     enum class State
//     {
//         ATTENTE,
//         RECHERCHE_FUSEE,
//         EXPLORATION,
//         PVP,
//         RECHERCHE_CIBLE,
//         TIRER
//     };

//     // Constructeur
//     StateMachine() : currentState(State::ATTENTE) {}

//     // Méthode pour effectuer une transition d'état
//     void transition()
//     {
//         switch (currentState)
//         {
//         case State::ATTENTE:
//             if (t_recherche_fusee)
//             {
//                 currentState = State::RECHERCHE_FUSEE;
//             }
//             if (t_recherche_fusee)
//             {
//                 currentState = State::RECHERCHE_FUSEE;
//             }
//             break;
//         case State::STATE1:
//             if (condition2())
//             {
//                 currentState = State::STATE2;
//             }
//             break;
//         case State::STATE2:
//             if (condition3())
//             {
//                 currentState = State::STATE3;
//             }
//             break;
//         case State::STATE3:
//             if (condition4())
//             {
//                 currentState = State::END;
//             }
//             break;
//         case State::END:
//             // La machine est dans l'état final, rien à faire
//             break;
//         }
//     }

//     // Méthodes de condition de garde pour chaque transition
//     bool condition1()
//     {
//         // Exemple de condition de garde pour la transition de INIT à STATE1
//         // Cette condition peut être basée sur des variables d'état ou des données externes
//         return true; // Exemple trivial, toujours vrai
//     }

//     bool condition2()
//     {
//         // Condition de garde pour la transition de STATE1 à STATE2
//         return true; // Exemple trivial, toujours vrai
//     }

//     bool condition3()
//     {
//         // Condition de garde pour la transition de STATE2 à STATE3
//         return true; // Exemple trivial, toujours vrai
//     }

//     bool condition4()
//     {
//         // Condition de garde pour la transition de STATE3 à END
//         return true; // Exemple trivial, toujours vrai
//     }

//     // Méthode pour récupérer l'état actuel de la machine
//     State getCurrentState() const
//     {
//         return currentState;
//     }

// private:
//     // Variable d'état actuelle de la machine
//     State currentState;
// };

// int main()
// {
//     StateMachine machine;

//     // Boucle de démonstration de la machine à états
//     while (machine.getCurrentState() != StateMachine::State::END)
//     {
//         switch (machine.getCurrentState())
//         {
//         case StateMachine::State::INIT:
//             cout << "Machine dans l'état INIT." << endl;
//             break;
//         case StateMachine::State::STATE1:
//             cout << "Machine dans l'état STATE1." << endl;
//             break;
//         case StateMachine::State::STATE2:
//             cout << "Machine dans l'état STATE2." << endl;
//             break;
//         case StateMachine::State::STATE3:
//             cout << "Machine dans l'état STATE3." << endl;
//             break;
//         case StateMachine::State::END:
//             cout << "Machine dans l'état END." << endl;
//             break;
//         }

//         // Effectuer une transition
//         machine.transition();
//     }

//     cout << "La machine est maintenant dans l'état final (END)." << endl;

//     return 0;
// }

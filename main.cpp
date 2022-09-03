#include <iostream>
#include <vector>





std::vector<char>operatori;
std::vector<double> numerini;
bool flagCalcolo = true;
char key_press;



//Aggiunge numeri ali vettori 
void numberAdd(float numb, char operetor){
    try
    {
       numerini.push_back(numb);
       operatori.push_back(operetor);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Errore" << '\n';
    }
    
}

//Controlla l'operatore e fa l'operazione 
void logic(){
    operatori.pop_back();
    double risulato = 0;
    for(int i = 0; i < numerini.size(); i++){
        if(i == 0){
            risulato += numerini[i];
        }else{
            if(operatori[i-1] == '+'){
                risulato += numerini[i];
            }else if(operatori[i-1] == '-'){
                risulato -= numerini[i];
            }else if(operatori[i-1] == '*'){
                risulato *= numerini[i];
            }else if(operatori[i-1] == '/'){
                risulato -= numerini[i];
            }
        }
    }
    std::cout << "Il risultato è " << risulato << std::endl;

}

int main(){
    // numerini.size()
    std::cout << "Iniziare le operazioni\n Operatori accettati:\n\t+\n\t-\n\t*\n\t/ \n\n = per ottenere i risulato in 'Operatore-:>'\n\n " << std::endl;
    std::cout << "Per usicre premere esc\nPremi ENTER per iniziare\n\n" <<std::endl;
   while(true){
        flagCalcolo = true;
        key_press = getchar();
        if(key_press == 27){
            break;
        }else if(key_press == 10){
            while (flagCalcolo){
                double number;
                char operetor;
                std::cout << "Numero-:>\t" << std::endl;
                std::cin >> number;
                if(!static_cast<double>(number)){
                    std::cout << "Hai inserito un valore errato" << std::endl;
                    flagCalcolo = false;
                }
                std::cout << "Operatore-:>\t"<< std::endl;
                std::cin >> operetor;
                // || operetor != "+" || operetor != "-" || operetor != "*" || operetor != "/"
                if(!static_cast<char>(operetor)){
                    std::cout << "Hai inserito un valore errato" << std::endl;
                    flagCalcolo = false;
                }
                if(int(operetor) == 42 || int(operetor) == 43 || int(operetor) == 45 || int(operetor) == 47 || int(operetor) == 61){
                    numberAdd(number,operetor);
                    if(operetor == '='){
                        logic();
                        flagCalcolo = false;
                    }
                }else{
                    std::cout << "Hai inserito un valore errato" << std::endl;
                    break;
                }
    
            }
        }else{
            std::cout << "Comando non riconosciuto! " << std::endl;
        }

   }

}
#include <iostream>
#include <unistd.h>
using namespace std;

class Facturacion{

    public:
        Facturacion(int productos_vendidos = 0, string nombre_productos[] = {}, double precio_productos[] = {}, int longitud = 0){
            if(productos_vendidos == 0 && longitud == 0){
                GenerarMasFacturas();
            }else{



                bool regresar = false;
                do{
                    int opcion_escogida = OpcionMenu();

                    if(opcion_escogida == 1){
                        regresar = false;
                         MostrarInformacion(productos_vendidos, nombre_productos, precio_productos, longitud);

                         char op;
                         int contador = 3;
                         //Que solamente se tenga tres intentos.... caso contrario detenemos el programa...

                         do{

                                cout << "\n[?] Deseas regresar al menu [Y/N]: "; cin >> op;
                                cout << "\n Numero de intentos [" << contador << "]" << endl;
                                 //Aceptamos solo estas letras Y y N (minusculas y mayusculas)
                                 if(op == 'Y' || op == 'y' || op == 'n' || op == 'N'){
                                        if(op == 'Y' || op == 'y'){
                                            system("clear");
                                            regresar = true;
                                            break;//para detener el programa.

                                        }else{
                                            system("clear");
                                            break; // salir del sistema cuando es [N/n]
                                        }
                                 }else{
                                    //cuando introduce una letra muy distinta a las predeterminadas.
                                    contador -= 1;

                                 }
                         }while(contador >= 0);

                    }else if(opcion_escogida == 2){
                        regresar = false;
                        CalcularUSD(precio_productos, longitud);

                        char op;
                         int contador = 3;
                         //Que solamente se tenga tres intentos.... caso contrario detenemos el programa...
                         do{

                                cout << "\n[?] Deseas regresar al menu [Y/N]: "; cin >> op;
                                cout << "\n Numero de intentos [" << contador << "]" << endl;
                                 //Aceptamos solo estas letras Y y N (minusculas y mayusculas)
                                 if(op == 'Y' || op == 'y' || op == 'n' || op == 'N'){
                                        if(op == 'Y' || op == 'y'){
                                            system("clear");
                                            regresar = true;
                                            break;//para detener el programa.

                                        }else{
                                            system("clear");
                                            break; // salir del sistema cuando es [N/n]
                                        }
                                 }else{
                                    //cuando introduce una letra muy distinta a las predeterminadas.
                                    contador -= 1;

                                 }
                         }while(contador >= 0);

                    }else if(opcion_escogida == 3){
                        regresar = false;//detenemos el programa para poder ejecutar otras cosas.....



                        GenerarMasFacturas();

                     }else{
                        //con solo poder esto va a detener el programa
                        break;
                     }
                }while(regresar);

            }//else....

        }


        int OpcionMenu(){
            system("clear");

             bool preguntar = true;

             while(preguntar){
                    system("clear");
                    cout << "**************************************" << endl;
                    cout << "*  [1] MOSTRAR INFORMACION FACTURA   *" << endl;
                    cout << "*  [2] VER TOTAL DE USD              *" << endl;
                    cout << "*  [3] SEGUIR CREANDO FACTURAS       *" << endl;
                    cout << "*  [4] SALIR PROGRAMA                *" << endl;
                    cout << "**************************************" << endl;

                    char op;
                    cout << "[>] INSERTA TU OPCION: "; cin >> op;

                    switch(op){
                        case '1':
                            return 1;
                            break;
                        case '2':
                            return 2;
                        case '3':
                            //para poder seguir creando nuestra facturacion....
                            return 3;

                        case '4':
                            preguntar = false;
                            break;


                    }
             }

        }


        void MostrarInformacion(int n, string n_p[], double p_p[], int l){
            system("clear");
            cout << "\n\t******************************************************" << endl;
            cout << "\t*   INFORMACION DE NUESTRA FACTURA                   *" << endl;
            cout << "\t******************************************************" << endl;
            cout << "\n" << endl;

            cout << "\t[*] TOTAL DE PRODUCTOS VENDIDOS: " << n << endl;
            cout << "\t[*] NOMBRE DE LOS PRODUCTOS: " << endl;
            cout << "\n";
            for(int i = 0; i < l; i++){
                cout << "\t\t" << i << "._ " << n_p[i] << endl;
            }

            cout << "\n\t[*] PRECIO DE LOS PRODUCTOS: " << endl;
            cout << "\n";
            for(int j = 0; j < l; j++){
                cout << "\t\t" << j << "._ " << p_p[j] << "$" << endl;
            }
        }

        void CalcularUSD(double p_p[], int l){
            //Calculamos todo el dinero... con los calculos necesarios...
            //[!] En Ecuador el IVA es del 12%.....
            system("clear");

            double sub_total = 0.0, iva = 0.0, total = 0.0;

            for(int i = 0; i < l; i++){
                sub_total += p_p[i];
            }

            //Con esta formula establecemos nuestro sub-total...
            sub_total = (sub_total*100) / 112;

            iva = (12*sub_total)/100;

            total = sub_total + iva;

            //IMPRIMIMOS NUESTROS CALCULOS GENERADOS.....
            cout << "\n";
            cout << "[*] SUB-TOTAL: " << sub_total << endl;
            cout << "[*] IVA: " << iva << endl;
            cout << "[*] TOTAL: " << total << endl;
        }

        void GenerarMasFacturas(){
            system("clear");
            cout << "\n\t********************************************************" << endl;
            cout << "\t*               SISTEMA DE FACTURACION                 *" << endl;
            cout << "\t********************************************************" << endl;
            sleep(3);
            system("clear");

            cout << "\n\n" << endl;
            int cantidad_productos = 0; //vendidos.. (no alterar)

            cout << "[>] Ingresa tu cantidad de productos vendidos: "; cin >> cantidad_productos;

            //vamos a guardar la informacion insertada...
            string producto_nombre[cantidad_productos] = {}; // (no alterar)
            double producto_precio[cantidad_productos] = {}; // (no alterar)
            int indexador = 0;

            int contador = cantidad_productos;
            /*Vamos a recorrer esa cantidad para que el usuario inserte el nombre y precio de cada producto.*/
            while(contador > 0){
                system("clear");
                cout << "[*] INFORMACION DE PRODUCTOS FALTANTES: [" << contador << "]" << endl;
                cout << "\n[>] Inserta el nombre del producto: "; cin >> producto_nombre[indexador];
                cout << "\n[>] Digita el precio del producto: "; cin >> producto_precio[indexador];


                indexador += 1;
                contador -= 1;
            }
            int longitud = sizeof(producto_nombre)/sizeof(producto_nombre[0]);

            //class
            Facturacion productos(cantidad_productos, producto_nombre, producto_precio, longitud);

        }
};


int main(){
    /*
        Una empresa de electrodomésticos ha pedido el desarrollo de
        un sistema de facturación que tenga un pequeño menú

        1) Ingresar una cantidad x de productos que han sido vendidos
        ingresar el nombre del producto y el precio.

        2) Ver listado de productos que se encuentran registrados en
        la venta (mostrar el detalle de la factura)

        3) Mostrar el subtotal, IVA y total de la venta

        4) Poder realizar varias facturas hasta que el usuario ya no
        desee generar un proceso que me permita salir del programa
    */
    Facturacion product;

    return 0;
}




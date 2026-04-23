#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// =============================================
// ESTRUCTURA DE DATOS
// =============================================

// ESTADO DE CADA UNA DE LAS PC QUE TENEMOS A NUESTRO RESGUARDO
struct Computadora
{
    int id;
    string estado; // "libre", "ocupada", "mantenimiento"
};

// REGISTRO EN NUESTRA BITACORA
struct RegistroBitacora
{
    int idEquipo;
    string hora;
    string tipoIncidente;
    string descripcion;
};

// =============================================
// VARIABLES
// =============================================

const int TOTAL_EQUIPOS = 20;
const int MAX_BITACORA = 100;
const string ARCHIVO = "bitacora.txt";

Computadora equipos[TOTAL_EQUIPOS];
RegistroBitacora bitacora[MAX_BITACORA];
int totalRegistros = 0;

// =============================================
// FUNCIONES
// =============================================

// ARRANCA LOS EQUIPOS
void inicializarEquipos()
{
    for (int i = 0; i < TOTAL_EQUIPOS; i++)
    {
        equipos[i].id = i + 1;
        equipos[i].estado = "libre";
    }
}

// EN ESTA PARTE NOS MUESTRA LOS ESTADOS DE NUESTROS EQUIPOS
void consultarEstado()
{
    cout << "\n--- ESTADO DE EQUIPOS ---\n";
    for (int i = 0; i < TOTAL_EQUIPOS; i++)
    {
        cout << "Equipo " << equipos[i].id
             << " -> " << equipos[i].estado << "\n";
    }
}

// ESTO CAMBIA EL ESTADO DE UN EQUIPO EN ESPECIFICO
void modificarEstado()
{
    int id;
    cout << "\nIngresa el numero de equipo (1-20): ";
    cin >> id;

    if (id < 1 || id > TOTAL_EQUIPOS)
    {
        cout << "Numero de equipo invalido.\n";
        return;
    }

    cout << "Nuevo estado (libre / ocupada / mantenimiento): ";
    string nuevoEstado;
    cin >> nuevoEstado;

    if (nuevoEstado != "libre" &&
        nuevoEstado != "ocupada" &&
        nuevoEstado != "mantenimiento")
    {
        cout << "Estado no valido.\n";
        return;
    }

    equipos[id - 1].estado = nuevoEstado;
    cout << "Equipo " << id << " actualizado a: " << nuevoEstado << "\n";
}

// REGISTRO DE ALGUN DETALLE O PROBLEMA EN BITACORA
void registrarIncidente()
{
    if (totalRegistros >= MAX_BITACORA)
    {
        cout << "Bitacora llena.\n";
        return;
    }

    RegistroBitacora reg;

    cout << "\nID del equipo: ";
    cin >> reg.idEquipo;

    if (reg.idEquipo < 1 || reg.idEquipo > TOTAL_EQUIPOS)
    {
        cout << "ID de equipo invalido.\n";
        return;
    }

    cin.ignore();

    cout << "Hora (ej. 10:30): ";
    getline(cin, reg.hora);
    if (reg.hora.empty())
    {
        cout << "La hora no puede estar vacia.\n";
        return;
    }

    cout << "Tipo de incidente (falla / uso / mantenimiento): ";
    getline(cin, reg.tipoIncidente);
    if (reg.tipoIncidente.empty())
    {
        cout << "El tipo no puede estar vacio.\n";
        return;
    }

    cout << "Descripcion: ";
    getline(cin, reg.descripcion);
    if (reg.descripcion.empty())
    {
        cout << "La descripcion no puede estar vacia.\n";
        return;
    }

    bitacora[totalRegistros] = reg;
    totalRegistros++;
    cout << "Incidente registrado correctamente.\n";
}

// NOS MUESTRA HISTORIAL DE NUESTRA BITACORA
void consultarHistorial()
{
    if (totalRegistros == 0)
    {
        cout << "\nNo hay registros en la bitacora.\n";
        return;
    }

    cout << "\n--- HISTORIAL DE BITACORA ---\n";
    for (int i = 0; i < totalRegistros; i++)
    {
        cout << "Equipo: " << bitacora[i].idEquipo
             << " | Hora: " << bitacora[i].hora
             << " | Tipo: " << bitacora[i].tipoIncidente
             << " | Desc: " << bitacora[i].descripcion << "\n";
    }
}

// GUARDA LA BITACORA EN NUESTRO ARCHIVO DE TEXTO
void guardarArchivo()
{
    ofstream archivo(ARCHIVO);
    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo para escritura.\n";
        return;
    }

    for (int i = 0; i < totalRegistros; i++)
    {
        archivo << bitacora[i].idEquipo << "|"
                << bitacora[i].hora << "|"
                << bitacora[i].tipoIncidente << "|"
                << bitacora[i].descripcion << "\n";
    }

    archivo.close();
    cout << "Datos guardados en " << ARCHIVO << "\n";
}

// ESTO LEE LA BITACORA EN CASO DE EXISTIR
void cargarArchivo()
{
    ifstream archivo(ARCHIVO);
    if (!archivo.is_open())
    {
        cout << "No se encontro bitacora previa. Iniciando desde cero.\n";
        return;
    }

    string linea;
    while (getline(archivo, linea) && totalRegistros < MAX_BITACORA)
    {
        // Separar por el caracter '|'
        RegistroBitacora reg;
        int pos = 0;
        string campo = "";
        int numCampo = 0;

        for (int i = 0; i <= (int)linea.size(); i++)
        {
            if (i == (int)linea.size() || linea[i] == '|')
            {
                switch (numCampo)
                {
                case 0:
                    reg.idEquipo = stoi(campo);
                    break;
                case 1:
                    reg.hora = campo;
                    break;
                case 2:
                    reg.tipoIncidente = campo;
                    break;
                case 3:
                    reg.descripcion = campo;
                    break;
                }
                campo = "";
                numCampo++;
            }
            else
            {
                campo += linea[i];
            }
        }

        if (numCampo == 4)
        {
            bitacora[totalRegistros] = reg;
            totalRegistros++;
        }
    }

    archivo.close();
    cout << "Bitacora cargada: " << totalRegistros << " registro(s) encontrado(s).\n";
}

// =============================================
// PROGRAMA MAIN
// =============================================

int main()
{
    inicializarEquipos();
    cargarArchivo();

    int opcion;

    do
    {
        cout << "\n============================================================================\n";
        cout << "                               SIG-Conecta                                         \n";
        cout << "============================================================================\n";
        cout << "\n============================================================================\n";
        cout << "   MM           MM   AAAAAA   -RRRRRRRRR   VV         VV   II   NNNN     NN\n";
        cout << "   MMMM       MMMM  AA    AA  -RR     RR    VV       VV    II   NN NN    NN\n";
        cout << "   MM  MM    MM MM  AA    AA  -RR    RR      VV     VV     II   NN  NN   NN\n";
        cout << "   MM   MM MM   MM  AAAAAAAA  -RRRRRR         VV   VV      II   NN   NN  NN\n";
        cout << "   MM    MMM    MM  AA    AA  -RR    RRR       VV VV       II   NN    NN NN\n";
        cout << "   MM     M     MM  AA    AA  -RR      RRR      VVV        II   NN     NNNN\n";
        cout << "============================================================================\n";
        cout << "============================================================================\n";
        cout << "                                 UNRC                                       " << endl;
        cout << "\n==========================================================================" << endl;
        cout << "1. Consultar estado de equipos\n";
        cout << "2. Modificar estado de equipo\n";
        cout << "3. Registrar incidente\n";
        cout << "4. Consultar historial\n";
        cout << "5. Guardar y salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            consultarEstado();
            break;
        case 2:
            modificarEstado();
            break;
        case 3:
            registrarIncidente();
            break;
        case 4:
            consultarHistorial();
            break;
        case 5:
            guardarArchivo();
            cout << "Hasta luego.\n";
            break;
        default:
            cout << "Opcion no valida.\n";
        }

    } while (opcion != 5);

    return 0;
}

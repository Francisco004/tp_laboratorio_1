#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Employee;

/** \brief Solicita espacio en memoria para un nuevo empleado.
 *
 * \return Employee*
 *
 */
Employee* employee_new();

/**
 *\brief llama al Set de datos del empleado.
 *\param idStr char*
 *\param nombreStr char*
 *\param horasTrabajadasStr char*
 *\param sueldoStr char*
 *\return Employee*
*/
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/** \brief realiza todos los gets en una sola funcion.
 *
 * \param this Employee*
 * \param nombre char*
 * \param horas int*
 * \param sueldo int*
 * \param id int*
 * \return int
 *
 */
int dameTodo(Employee* this,char* nombre,int* horas,int* sueldo,int* id);

/** \brief elimina y libera espacio del empleado que ya no se use.
 *
 * \param this Employee*
 * \return int
 *
 */
int employee_delete(Employee* borrarEmpleado);

/** \brief Generador del siguiente de ID ascendente.
 *
 * \return int
 *
 */
int dameLaProximaID();


/** \brief Set del ID del empleado.
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* setID,int id);

/** \brief funcion get para tomar el ID del empleado.
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* dameID, int* id);

/** \brief setea el nombre del empleado.
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* setNombre, char* nombre);

/** \brief funcion para tomar el nombre del empleado.
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* dameNombre, char* nombre);

/** \brief seteo de las horas trabajadas del empleado.
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* setHoras,int horasTrabajadas);

/** \brief funcion para tomar las horas trabajadas del empleado.
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* dameHoras, int* horasTrabajadas);

/** \brief seteo del sueldo del empleado.
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* setSalario, int sueldo);

/** \brief funcion get para tomar el sueldo del empleado.
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* dameSalario, int* sueldo);

/** \brief Generador empleado y se fija que no este vacio.
 *
 * \param nombre char*
 * \param horasTrabajadas int
 * \param sueldo int
 * \return Employee*
 *
 */
Employee* generadorDeID(char* nombre,int horasTrabajadas,int sueldo);

/** \brief Base a tomar para realizar un ordenamiento de empleados por nombre.
 *
 * \param thisA void*
 * \param thisB void*
 * \return int
 *
 */
int ordenamientoPorNombre(void* x,void* y);

#endif // employee_H_INCLUDED

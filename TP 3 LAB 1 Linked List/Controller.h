#include "Employee.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv modo texto.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv modo binario.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados en modo texto.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo modo texto.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo modo binario.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados de modo texto.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int aniadirEmpleadoTexto(LinkedList* pArrayListEmployee);

/** \brief Alta de empleados de modo binario.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int aniadirEmpleadoBinario(LinkedList* pArrayListEmployee);

/** \brief Busca y muestra los datos dependiendo de la id
 *
 * \param pArrayListEmployee LinkedList*
 * \param int
 * \return void
 *
 */
void buscarEmpleadoEspecifico(LinkedList* pArrayListEmployee, int);

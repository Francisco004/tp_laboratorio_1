/** \brief Parsea los datos de los empleados desde el archivo en formato texto.
 *
 * \param FILE* pFile
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee);

/** \brief Parsea los datos de los empleados desde el archivo en formato binario.
 *
 * \param FILE* pFile*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee);

/** \brief Parsea los datos de los empleados para guardar en el archivo formato texto.
 *
 * \param FILE* pFile
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int guardarFormatoTexto(FILE*, LinkedList*);

/** \brief Parsea los datos de los empleados para guardar en el archivo formato binario.
 *
 * \param FILE* pFile
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int guardarFormatoBinario(FILE*, LinkedList*);

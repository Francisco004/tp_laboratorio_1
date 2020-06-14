/** \brief pide un nombre y lo valida.
 *
 * \param pNombre char*
 * \param limite int
 * \param msg char*
 * \param msgErr char*
 * \param reintentos int
 * \return int
 *
 */
int dameNombre(char* pNombre, int limite, char* msg, char* msgErr, int reintentos);

/** \brief pide un texto y lo valida.
 *
 * \param pTexto char*
 * \param limite int
 * \param mensaje char*
 * \param mensajeError char*
 * \param reintentos int
 * \return int
 *
 */
int dameTexto(char *pTexto, int limite, char *mensaje,char *mensajeError, int reintentos);

/** \brief valida un texto
 *
 * \param pBuffer char*
 * \param limite int
 * \return int
 *
 */
int validacionDeTexto(char *pBuffer, int limite);

/** \brief pide y valida una cadena.
 *
 * \param pBuffer char*
 * \param limite int
 * \return int
 *
 */
int getString(char* pBuffer, int limite);

/** \brief pide y valida un numero entero.
 *
 * \param pResultado int*
 * \param mensaje[] char
 * \param mensajeError[] char
 * \param minimo int
 * \param maximo int
 * \param reintentos int
 * \return int
 *
 */
int getInt(int* pResultado, char mensaje[], char mensajeError[], int  minimo, int  maximo, int  reintentos);

/** \brief verifica el nombre del empleado.
 *
 * \param pBuffer char*
 * \param limite int
 * \return int
 *
 */
int validarNombre(char* pBuffer,int limite);

/** \brief verifica si el numero es entero.
 *
 * \param pBuffer char*
 * \return int
 *
 */
int esEntero(char* pBuffer);

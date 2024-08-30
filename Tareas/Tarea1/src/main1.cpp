/*
 * MIT License
 * 
 * Copyright (c) 2024 [Rodrigo Sánchez, UNiversidad de Costa Rica]
 * 
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "conversiones.hpp"

using namespace std;

int main(){
    int option;
    converDatos data;
    do{
        showMenu();
        cout <<"Elija una opción: " << endl;
        cin >> option;

        switch(option){
            case CONVERTIR_LONGITUD:
                convLongitud(data);
                break;
            case CONVERTIR_PESO:
                convPeso(data);
                break;
            case CONVERTIR_TEMPERATURA:
                convTemperatura(data); 
                break;
        }

    } while(option != SALIR);

    return 0;
} 


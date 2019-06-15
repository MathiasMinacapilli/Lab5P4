//Librerias de C
#include <iostream>
using namespace std;

//Archivos
#include "../include/ControladorProducto.hpp"

ControladorProducto *ControladorProducto::instance = nullptr;

ControladorProducto::ControladorProducto(){}

//PATRON SINGLETON
/* Retorna la instancia del controlador la cual es unica por la aplicacion del
patron de diseño Singleton. */
ControladorProducto *ControladorProducto::getInstance(){
	if (instance == nullptr)
		instance = new ControladorProducto();
	return instance;
}

//ALTA PRODUCTO
/* Retorna true si existe al menos un producto simple en la coleccion de productos
simples del controlador. */
bool ControladorProducto::existeProductoSimple(){
	return !productosSimples.empty();
}

/* Ingresa los datos del producto al sistema, si ya existe un producto
con el codigo ingresado se lanza una excepcion. */
void ControladorProducto::ingresarDatosProducto(DtProductoSimple datos){
	DtProductoCantidad datos_producto = DtProductoCantidad(DtProducto(datos.getCodigo(), datos.getDescripcion(), datos.getPrecio()), 1);
	if(this->encontrarProducto(datos_producto) == nullptr) {
		this->datos_prod_simple = datos;
	} else {
		throw new invalid_argument("Ya existe un producto con el codigo ingresado");
	}
}

/* Agrega el producto simple recordado por el controlador a la coleccion
de productos simples almacenada en el controlador. */
void ControladorProducto::ingresarProductoSimple(){
	ProductoSimple *nuevo_prod_simple = new ProductoSimple((this->datos_prod_simple).getCodigo(), (this->datos_prod_simple).getDescripcion(), (this->datos_prod_simple).getPrecio());
	this->productosSimples[nuevo_prod_simple->getCodigo()] = nuevo_prod_simple;
}

/* Cancela el alta de un producto simple */
void ControladorProducto::cancelarProductoSimple(){
	//Ver que "olvidar"
}

/* Ingresa los datos del menu al controlador para que este los recuerde */
void ControladorProducto::ingresarDatosMenu(int codigo, string desc){
	this->codigo_menu = codigo;
	this->desc_menu = desc;
}

/* Devuelve la coleccion de productos simples almacenada en el controlador */
map<int, DtProducto> ControladorProducto::getProductosSimples(){
	map<int, DtProducto> resultado;
	map<int, ProductoSimple *>::iterator it;
	for (it = this->productosSimples.begin(); it != this->productosSimples.end(); ++it){
		DtProducto prod = (it->second)->getDatosProducto();
		resultado[(it->second)->getCodigo()] = prod;
	}
	return resultado;
}

/* Agrega a la coleccion de ProductoCantidad recordada por el controlador el
producto_cantidad ingresado. */
void ControladorProducto::seleccionarProductoYCantidad(DtProductoCantidad producto_cantidad){
		this->prod_cants_recordados[producto_cantidad.getProducto().getCodigo()] = producto_cantidad;
}

/* Ingresa el menu a la coleccion de menus almacenada en el controlador con
los datos recordados por el mismo. */
void ControladorProducto::ingresarMenu(){
	//creo el nuevo menu con los parametros que el usuario ingreso anteriormente
	Menu *nuevo_menu = new Menu(this->codigo_menu, this->desc_menu);
	//guardo el menu en la coleccion de menus
	menus[nuevo_menu->getCodigo()] = nuevo_menu;
	//recorro los DtProductoCantidad recordados
	//y agrego los productos correspondientes al menu
	map<int, DtProductoCantidad>::iterator it;
	for (it = this->prod_cants_recordados.begin(); it != this->prod_cants_recordados.end(); ++it){
		map<int, ProductoSimple*>::iterator it_ps = (this->productosSimples).find((it->second).getProducto().getCodigo());
		if(it_ps != productosSimples.end()){
			ProductoSimple *p = it_ps->second;
			nuevo_menu->agregarProducto(p, (it->second).getCantidad());
		}
	}
	this->prod_cants_recordados.clear();
}

/* Cancela el alta del menu */
void ControladorProducto::cancelarMenu(){
	//libera la "memoria" (cosas recordadas)
	this->prod_cants_recordados.clear();
	this->codigo_menu = -1;
	this->desc_menu = ' ';
}


//BAJA PRODUCTO
/* Retorna una coleccion de productos que representa a los productos
disponibles del sistema */
map<int, DtProducto> ControladorProducto::getProductosDisponibles(){
	map<int, DtProducto> resultado;
	map<int, ProductoSimple *>::iterator it_prod_simp;
	for(it_prod_simp = this->productosSimples.begin(); it_prod_simp != this->productosSimples.end(); ++it_prod_simp)
		resultado[(it_prod_simp->second)->getCodigo()] = (it_prod_simp->second)->getDatosProducto();
	map<int, Menu *>::iterator it_menu;
	for(it_menu = this->menus.begin(); it_menu != this->menus.end(); ++it_menu)
		resultado[(it_menu->second)->getCodigo()] = (it_menu->second)->getDatosProducto();
	return resultado;
}

/* Ingresa el codigo del producto a recordar por el controlador. Si el codigo
no es un codigo valido la operacion lanza una excepcion de invalid_argument */
void ControladorProducto::seleccionarProducto(int codigo_producto){
	map<int, ProductoSimple *>::iterator it_ps = this->productosSimples.find(codigo_producto);
	//si es un producto simple
	if (it_ps != this->productosSimples.end())
		this->producto_recordado = this->productosSimples[codigo_producto];
	else {
		map<int, Menu *>::iterator it_m = this->menus.find(codigo_producto);
		//si es un menu
		if (it_m != this->menus.end())
			this->producto_recordado = this->menus[codigo_producto];
		//no existe producto con ese codigo
		else {
			this->producto_recordado = nullptr;
			throw new invalid_argument ("No existe producto con ese código.");
		}
	}
}

/* Elimina el producto recordado por el controlador del sistema */
bool ControladorProducto::eliminarProducto(){
	ControladorVenta *controlador_venta = ControladorVenta::getInstance();
	bool esta_activo = controlador_venta->estaEnVentaSinFacturar(this->producto_recordado);
	if (!esta_activo) {
        if (dynamic_cast<ProductoSimple*>(producto_recordado) != nullptr)
            productosSimples.erase(producto_recordado -> getCodigo());
        else
            menus.erase(producto_recordado -> getCodigo());
		producto_recordado->eliminar();
    }
	return !esta_activo;
}

/* Cancela la baja de un producto */
void ControladorProducto::cancelarBajaProducto(){
	this->producto_recordado = nullptr;
}

/* Elimina el producto con codigo cod de todos los menus del sistema */
void ControladorProducto::eliminarProductoDeMenu(int cod){
	map<int, Menu *>::iterator it;
  	map<int, ProductoEnMenu*> prods_menu;
	for (it = this->menus.begin(); it != this->menus.end(); ++it) {
        prods_menu = ((it -> second) -> getProductos());
		map<int, ProductoEnMenu*>::iterator it_p = (prods_menu.find(cod));
        if ( it_p != prods_menu.end()) {
            bool vacio_menu = (it->second) -> eliminarProducto(cod);
            if(vacio_menu) {
                Menu* menu = it -> second;
                menus.erase(menu -> getCodigo());
				menu -> eliminar();
            }
        }
    }
}


//AGREGAR PRODUCTO A VENTA
/* Si existe un producto con codigo producto_cantidad.producto.codigo en el sistema,
se retorna el objeto Producto*. En caso contrario se retorna null */
Producto * ControladorProducto::encontrarProducto(DtProductoCantidad producto_cantidad){
	int codigo = producto_cantidad.getProducto().getCodigo();
	map<int, ProductoSimple *>::iterator it_ps = this->productosSimples.find(codigo);
	//si es un producto simple
	if (it_ps != this->productosSimples.end())
		return this->productosSimples[codigo];
	else {
		map<int, Menu *>::iterator it_m = this->menus.find(codigo);
		//si es un menu
		if (it_m != this->menus.end())
			return this->menus[codigo];
		else return nullptr;
	}
}

//Caso de uso: informacion de un producto
/* Devuelve true sii existe un producto en el sistema con codigo codigo */
bool ControladorProducto::ingresarCodigoProductoAConsultar(int codigo) {
	DtProductoCantidad datos_producto = DtProductoCantidad(DtProducto(codigo, "", 0), 1);
	if(encontrarProducto(datos_producto) != nullptr) {
		this->codigoProductoAConsultar = codigo;
		return true;
	} else {
		return false;
	}
}
/* Cancela el pedido de informacion de un producto */
void ControladorProducto::cancelarInformacion() {
	this->codigoProductoAConsultar = 0;
}
/* Devuelve los datos del producto con codigo recordado por el controlador */
DtProducto* ControladorProducto::getProducto() {
	DtProducto dt_prod = DtProducto(this->codigoProductoAConsultar, "", 1);
	DtProductoCantidad datos_producto = DtProductoCantidad(dt_prod, 1);
	Producto* prod = encontrarProducto(datos_producto);
	DtProducto* dtprod;
	//Primero casteo al objeto hijo, obtengo el dt y lo que hago es tener un puntero
	//al dt para poder castearlo al DtProducto que es la clase base
	if(dynamic_cast<ProductoSimple*>(prod) != nullptr) {
		ProductoSimple* prod_simple = dynamic_cast<ProductoSimple*>(prod);
		DtProductoSimple* datos_prod_simple = new DtProductoSimple(prod_simple->getCodigo(), prod_simple->getDescripcion(), prod_simple->getPrecio(), prod_simple->getCantidadVendidos());
		dtprod = dynamic_cast<DtProducto*>(datos_prod_simple);
	} else { //Es Menu*
		Menu* datos_menu = dynamic_cast<Menu*>(prod);
		map<int, ProductoEnMenu*> prods_en_menu = datos_menu->getProductos();
		map<int, ProductoEnMenu*>::iterator it;
		map<int, DtProductoEnMenu> dt_prods_en_menu;
		for(it = prods_en_menu.begin(); it != prods_en_menu.end(); ++it) {
			DtProducto prod_en_menu = it->second->getProducto()->getDatosProducto();
			DtProductoSimple dt_prod_simple = DtProductoSimple(prod_en_menu.getCodigo(), prod_en_menu.getDescripcion(), prod_en_menu.getPrecio());
			dt_prods_en_menu[it->second->getProducto()->getCodigo()] = DtProductoEnMenu(dt_prod_simple, it->second->getCantidad());
		}
		DtMenu* dt_menu = new DtMenu(datos_menu->getCodigo(), datos_menu->getDescripcion(), datos_menu->getPrecio(), dt_prods_en_menu);
		dtprod = dynamic_cast<DtProducto*>(dt_menu);
	}
	return dtprod;
}

/* Devuelve la cantidad de vendidos del producto */
int ControladorProducto::getCantidadProductoTotalVendidos() {
	DtProductoCantidad datos_producto = DtProductoCantidad(DtProducto(this->codigoProductoAConsultar, "", 0), 1);
	Producto* prod = encontrarProducto(datos_producto);
	if (prod != nullptr) {
		int cantidad_vendidos = prod->getCantidadVendidos();
		return cantidad_vendidos;
	} else
		return 0;
}

/* Agrega el producto simple ps a la coleccion ??? */
void ControladorProducto::agregarProductoSimple(ProductoSimple *ps) {
	map<int, ProductoSimple*>::iterator it = this -> productosSimples.find(ps -> getCodigo());
	if (it == this -> productosSimples.end())
		(this -> productosSimples).insert(pair<int, ProductoSimple*>(ps -> getCodigo(), ps));
	else
		throw new invalid_argument("Ya existe un producto con el codigo ingresado.");
}

/* Agrega el menu a la coleccion de menus si no existe menu con codigo
igual al menu recibido por parametro */
void ControladorProducto::agregarMenu(Menu *menu) {
	map<int, Menu*>::iterator it = this -> menus.find(menu -> getCodigo());
	if (it == this -> menus.end())
		(this -> menus).insert(pair<int, Menu*>(menu -> getCodigo(), menu));
	else
		throw new invalid_argument("Ya existe un producto con el codigo ingresado.");
}

//caso de uso: venta a domicilio
/* Retorna una coleccion de CantidadProducto la cual representa a los objetos
CantidadProducto recordados por el sistema */
map<int, CantidadProducto*> ControladorProducto::getProductosAlmacenados(bool &tiene_menu) {
    map<int, DtProductoCantidad>::iterator it_pc;
    map<int, ProductoSimple *>::iterator it_ps;
    map<int, Menu *>::iterator it_m;
    map<int, CantidadProducto*> res;
    res.clear();
    for(it_pc = prod_cants_recordados.begin(); it_pc != prod_cants_recordados.end(); ++it_pc) {
        int codigo = (it_pc -> first);
        int cantidad = (it_pc -> second).getCantidad();
        for(it_ps = productosSimples.begin(); it_ps != productosSimples.end(); ++it_ps) {
            if (codigo == (it_ps -> first)) {
                CantidadProducto* cant_prod = new CantidadProducto(cantidad, (it_ps -> second));
                res[codigo] =  cant_prod;
            }
        }
        for(it_m = menus.begin(); it_m != menus.end(); ++it_m) {
            if (codigo == (it_m -> first)) {
                CantidadProducto* cant_prod = new CantidadProducto(cantidad, (it_m -> second));
                res[codigo] =  cant_prod;
                tiene_menu = true;
            }
        }
    }
    return res;
}

void ControladorProducto::borrarProductos(){
	this->prod_cants_recordados.clear();
}

map<int, DtProductoCantidad> ControladorProducto::getDatosIngresadosMenu() {
	return this -> prod_cants_recordados;
}

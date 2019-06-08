//Archivos
#include "../include/ControladorProducto.hpp"

//ControladorProducto::ControladorProducto(){}

//PATRON SINGLETON
ControladorProducto *ControladorProducto::getInstance(){
	if (instance == nullptr)
		instance = new ControladorProducto();
	return instance;
}

//ALTA PRODUCTO
bool ControladorProducto::existeProductoSimple(){
	return !productosSimples.empty();
}

void ControladorProducto::ingresarDatosProducto(DtProductoSimple datos){
	this->datos_prod_simple = datos;
}

void ControladorProducto::ingresarProductoSimple(){
	ProductoSimple *nuevo_prod_simple = new ProductoSimple((this->datos_prod_simple).getCodigo(), (this->datos_prod_simple).getDescripcion(), (this->datos_prod_simple).getPrecio());
	this->productosSimples[nuevo_prod_simple->getCodigo()] = nuevo_prod_simple;
}

void ControladorProducto::cancelarProductoSimple(){
}

void ControladorProducto::ingresarDatosMenu(int codigo, string desc){
	this->codigo_menu = codigo;
	this->desc_menu = desc;
}

map<int, DtProducto> ControladorProducto::getProductosSimples(){
	map<int, DtProducto> resultado;
	map<int, ProductoSimple *>::iterator it;
	for (it = this->productosSimples.begin(); it != this->productosSimples.end(); ++it){
			DtProducto prod = (it->second)->getDatosProducto();
			resultado[(it->second)->getCodigo()] = prod;
	}
	return resultado;
}

void ControladorProducto::seleccionarProductoYCantidad(DtProductoCantidad producto_cantidad){
	this->prod_cants_recordados[producto_cantidad.getProducto().getCodigo()] = producto_cantidad;
}


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
}

void ControladorProducto::cancelarMenu(){
	//libera la "memoria" (cosas recordadas)
	this->prod_cants_recordados.clear();
	this->codigo_menu = -1;
	this->desc_menu = ' ';
}


//BAJA PRODUCTO
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
			throw new invalid_argument ("No existe producto con ese código.")
		}
	}
}

bool ControladorProducto::eliminarProducto(){
	ControladorVenta *controlador_venta = ControladorVenta::getInstance();
	bool esta_activo = controlador_venta->estaEnVentaSinFacturar(this->producto_recordado);
	if (!esta_activo)
		producto_recordado->eliminar();
	return !esta_activo;
}

void ControladorProducto::cancelarBajaProducto(){
	this->producto_recordado = nullptr;
}

void ControladorProducto::eliminarProductoDeMenu(int cod){
	map<int, Menu *>::iterator it;
	for (it = this->menus.begin(); it != this->menus.end(); ++it)
		it->second->eliminarProducto(cod);
}


//AGREGAR PRODUCTO A VENTA
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

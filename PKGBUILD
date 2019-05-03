# This is an example PKGBUILD file. Use this as a start to creating your own,
# and remove these comments. For more information, see 'man PKGBUILD'.
# NOTE: Please fill out the license field for your package! If it is unknown,
# then please put 'unknown'.

# Maintainer: Your Name <youremail@domain.com> pkgname=sinesay
pkgname=sinesay
pkgver=0.1
pkgrel=1
#epoch=
pkgdesc="Plot a vertial sine wave in terminal with given string."
arch=('any')
#url=""
license=('GPL')
#groups=()
#depends=()
makedepends=('gcc')
#checkdepends=()
#optdepends=()
#provides=()
#conflicts=()
#replaces=()
#backup=()
#options=()
#install=
#changelog=
source=('sine-terminal.cc' 'Makefile')
noextract=()
md5sums=('95d879ac770d16801629e4ad2e34f175'
         '66c598836e8a62982fe84181b6d212ca')
#validpgpkeys=()

#prepare() {
#	cd "$pkgname-$pkgver"
#	patch -p1 -i "$srcdir/$pkgname-$pkgver.patch"
#}

build() {
        echo $srcdir
        echo $pkgdir
	#cd "$pkgname-$pkgver"
	#./configure --prefix=/usr
	make
}

#check() {
#	cd "$pkgname-$pkgver"
#	make -k check
#}

package() {
	#cd "$pkgname-$pkgver"
	make DESTDIR="$pkgdir/" install
}

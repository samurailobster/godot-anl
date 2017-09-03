#include "noise.h"

AnlNoise::AnlNoise(): vm(kernel), eb(kernel) {}
//------------------------------------------------------------------------------
// Kernel methods
//------------------------------------------------------------------------------
Index AnlNoise::pi() {

    auto pi = kernel.pi();
    return pi.getIndex();
}

Index AnlNoise::e() {

    auto e = kernel.e();
    return e.getIndex();
}

Index AnlNoise::one() {

    auto one = kernel.one();
    return one.getIndex();
}

Index AnlNoise::zero() {

    auto zero = kernel.zero();
    return zero.getIndex();
}

Index AnlNoise::point5() {

    auto point5 = kernel.point5();
    return point5.getIndex();
}

Index AnlNoise::sqrt2() {

    auto sqrt2 = kernel.sqrt2();
    return sqrt2.getIndex();
}

Index AnlNoise::constant(double value) {

    auto constant = kernel.constant(value);
    return constant.getIndex();
}

Index AnlNoise::seed(unsigned int value) {

    auto seed = kernel.seed(value);
    return seed.getIndex();
}

Index AnlNoise::value_basis(Index interp, Index seed) {

    auto value_basis = kernel.valueBasis(kernel[interp], kernel[seed]);
    return value_basis.getIndex();
}

Index AnlNoise::gradient_basis(Index interp, Index seed) {

    auto gradient_basis = kernel.gradientBasis(kernel[interp], kernel[seed]);
    return gradient_basis.getIndex();
}

Index AnlNoise::simplex_basis(Index seed) {

    auto simplex_basis = kernel.simplexBasis(kernel[seed]);
    return simplex_basis.getIndex();
}

Index AnlNoise::cellular_basis(const PoolVector<int>& f,
                               const PoolVector<int>& d,
                               Index distance, Index seed) {

    ERR_FAIL_COND_V(f.size() < 4, 0);
    ERR_FAIL_COND_V(d.size() < 4, 0);

    auto cellular_basis = kernel.cellularBasis(
        kernel[ f[0] ], kernel[ f[1] ], kernel[ f[2] ], kernel[ f[3] ],
        kernel[ d[0] ], kernel[ d[1] ], kernel[ d[2] ], kernel[ d[3] ],
        kernel[distance], kernel[seed]
    );
    return cellular_basis.getIndex();
}

Index AnlNoise::add(Index src1, Index src2) {

    auto add = kernel.add(kernel[src1], kernel[src2]);
    return add.getIndex();
}

Index AnlNoise::subtract(Index src1, Index src2) {

    auto subtract = kernel.subtract(kernel[src1], kernel[src2]);
    return subtract.getIndex();
}

Index AnlNoise::multiply(Index src1, Index src2) {

    auto multiply = kernel.multiply(kernel[src1], kernel[src2]);
    return multiply.getIndex();
}

Index AnlNoise::divide(Index src1, Index src2) {

    auto divide = kernel.divide(kernel[src1], kernel[src2]);
    return divide.getIndex();
}

Index AnlNoise::maximum(Index src1, Index src2) {

    auto maximum = kernel.maximum(kernel[src1], kernel[src2]);
    return maximum.getIndex();
}

Index AnlNoise::minimum(Index src1, Index src2) {

    auto minimum = kernel.minimum(kernel[src1], kernel[src2]);
    return minimum.getIndex();
}

Index AnlNoise::abs(Index src) {

    auto abs = kernel.abs(kernel[src]);
    return abs.getIndex();
}

Index AnlNoise::pow(Index src1, Index src2) {

    auto pow = kernel.pow(kernel[src1], kernel[src2]);
    return pow.getIndex();
}

Index AnlNoise::bias(Index src1, Index src2) {

    auto bias = kernel.bias(kernel[src1], kernel[src2]);
    return bias.getIndex();
}

Index AnlNoise::gain(Index src1, Index src2) {

    auto gain = kernel.gain(kernel[src1], kernel[src2]);
    return gain.getIndex();
}

Index AnlNoise::scale(Index src, Index p_scale) {

    auto scale = kernel.scaleDomain(kernel[src], kernel[p_scale]);
    return scale.getIndex();
}

Index AnlNoise::scale_x(Index src, Index scale) {

    auto scale_x = kernel.scaleX(kernel[src], kernel[scale]);
    return scale_x.getIndex();
}

Index AnlNoise::scale_y(Index src, Index scale) {

    auto scale_y = kernel.scaleY(kernel[src], kernel[scale]);
    return scale_y.getIndex();
}

Index AnlNoise::scale_z(Index src, Index scale) {

    auto scale_z = kernel.scaleZ(kernel[src], kernel[scale]);
    return scale_z.getIndex();
}

Index AnlNoise::scale_w(Index src, Index scale) {

    auto scale_w = kernel.scaleW(kernel[src], kernel[scale]);
    return scale_w.getIndex();
}

Index AnlNoise::scale_u(Index src, Index scale) {

    auto scale_u = kernel.scaleU(kernel[src], kernel[scale]);
    return scale_u.getIndex();
}

Index AnlNoise::scale_v(Index src, Index scale) {

    auto scale_v = kernel.scaleV(kernel[src], kernel[scale]);
    return scale_v.getIndex();
}

Index AnlNoise::translate(Index src, Index p_translate) {

    auto translate = kernel.translateDomain(kernel[src], kernel[p_translate]);
    return translate.getIndex();
}

Index AnlNoise::translate_x(Index src, Index translate) {

    auto translate_x = kernel.translateX(kernel[src], kernel[translate]);
    return translate_x.getIndex();
}

Index AnlNoise::translate_y(Index src, Index translate) {

    auto translate_y = kernel.translateY(kernel[src], kernel[translate]);
    return translate_y.getIndex();
}

Index AnlNoise::translate_z(Index src, Index translate) {

    auto translate_z = kernel.translateZ(kernel[src], kernel[translate]);
    return translate_z.getIndex();
}

Index AnlNoise::translate_w(Index src, Index translate) {

    auto translate_w = kernel.translateW(kernel[src], kernel[translate]);
    return translate_w.getIndex();
}

Index AnlNoise::translate_u(Index src, Index translate) {

    auto translate_u = kernel.translateU(kernel[src], kernel[translate]);
    return translate_u.getIndex();
}

Index AnlNoise::translate_v(Index src, Index translate) {

    auto translate_v = kernel.translateV(kernel[src], kernel[translate]);
    return translate_v.getIndex();
}

Index AnlNoise::y() {

    auto y = kernel.y();
    return y.getIndex();
}

Index AnlNoise::select(Index low, Index high, Index control,
                       Index threshold, Index falloff) {

    auto select = kernel.select(
        kernel[low], kernel[high], kernel[control],
        kernel[threshold], kernel[falloff]
    );
    return select.getIndex();
}
//------------------------------------------------------------------------------
// NoiseExecutor methods
//------------------------------------------------------------------------------
double AnlNoise::scalar_2d(double x, double y, Index index) {

    return vm.evaluateScalar(x, y, index);
}

void AnlNoise::_bind_methods() {

    ClassDB::bind_method(D_METHOD("pi"),&AnlNoise::pi);
    ClassDB::bind_method(D_METHOD("e"),&AnlNoise::e);
    ClassDB::bind_method(D_METHOD("one"),&AnlNoise::one);
    ClassDB::bind_method(D_METHOD("zero"),&AnlNoise::zero);
    ClassDB::bind_method(D_METHOD("point5"),&AnlNoise::point5);
    ClassDB::bind_method(D_METHOD("sqrt2"),&AnlNoise::sqrt2);

    ClassDB::bind_method(D_METHOD("constant", "value"),&AnlNoise::constant);
    ClassDB::bind_method(D_METHOD("seed", "value"),&AnlNoise::seed);

    ClassDB::bind_method(D_METHOD("value_basis", "interp_index", "seed_index"),&AnlNoise::value_basis);
    ClassDB::bind_method(D_METHOD("gradient_basis", "interp_index", "seed_index"),&AnlNoise::gradient_basis);
    ClassDB::bind_method(D_METHOD("simplex_basis", "seed_index"),&AnlNoise::simplex_basis);
    ClassDB::bind_method(D_METHOD("cellular_basis", "f4_indexes", "d4_indexes", "distance_index", "seed_index"),&AnlNoise::cellular_basis);

    ClassDB::bind_method(D_METHOD("add", "src1_index", "src2_index"),&AnlNoise::add);
    ClassDB::bind_method(D_METHOD("subtract", "src1_index", "src2_index"),&AnlNoise::subtract);
    ClassDB::bind_method(D_METHOD("multiply", "src1_index", "src2_index"),&AnlNoise::multiply);
    ClassDB::bind_method(D_METHOD("divide", "src1_index", "src2_index"),&AnlNoise::divide);
    ClassDB::bind_method(D_METHOD("maximum", "src1_index", "src2_index"),&AnlNoise::maximum);
    ClassDB::bind_method(D_METHOD("minimum", "src1_index", "src2_index"),&AnlNoise::minimum);
    ClassDB::bind_method(D_METHOD("abs", "src_index"),&AnlNoise::abs);
    ClassDB::bind_method(D_METHOD("pow", "src1_index", "src2_index"),&AnlNoise::pow);
    ClassDB::bind_method(D_METHOD("bias", "src1_index", "src2_index"),&AnlNoise::bias);
    ClassDB::bind_method(D_METHOD("gain", "src1_index", "src2_index"),&AnlNoise::gain);

    ClassDB::bind_method(D_METHOD("scale", "src_index", "scale_index"),&AnlNoise::scale);

    ClassDB::bind_method(D_METHOD("scale_x", "src_index", "scale_index"),&AnlNoise::scale_x);
    ClassDB::bind_method(D_METHOD("scale_y", "src_index", "scale_index"),&AnlNoise::scale_y);
    ClassDB::bind_method(D_METHOD("scale_z", "src_index", "scale_index"),&AnlNoise::scale_z);
    ClassDB::bind_method(D_METHOD("scale_w", "src_index", "scale_index"),&AnlNoise::scale_w);
    ClassDB::bind_method(D_METHOD("scale_u", "src_index", "scale_index"),&AnlNoise::scale_u);
    ClassDB::bind_method(D_METHOD("scale_v", "src_index", "scale_index"),&AnlNoise::scale_v);

    ClassDB::bind_method(D_METHOD("translate", "src_index", "translate_index"),&AnlNoise::translate);

    ClassDB::bind_method(D_METHOD("translate_x", "src_index", "translate_index"),&AnlNoise::translate_x);
    ClassDB::bind_method(D_METHOD("translate_y", "src_index", "translate_index"),&AnlNoise::translate_y);
    ClassDB::bind_method(D_METHOD("translate_z", "src_index", "translate_index"),&AnlNoise::translate_z);
    ClassDB::bind_method(D_METHOD("translate_w", "src_index", "translate_index"),&AnlNoise::translate_w);
    ClassDB::bind_method(D_METHOD("translate_u", "src_index", "translate_index"),&AnlNoise::translate_u);
    ClassDB::bind_method(D_METHOD("translate_v", "src_index", "translate_index"),&AnlNoise::translate_v);

    ClassDB::bind_method(D_METHOD("y"),&AnlNoise::y);
    ClassDB::bind_method(D_METHOD("select", "low_index", "high_index", "control_index", "threshold_index", "falloff_index"),&AnlNoise::select);

    ClassDB::bind_method(D_METHOD("scalar_2d", "x", "y", "index"),&AnlNoise::scalar_2d);

    using namespace anl;
    // Use namespace declaration to avoid having
    // prepended namespace name in enum constants
    BIND_ENUM_CONSTANT(INTERP_NONE);
    BIND_ENUM_CONSTANT(INTERP_LINEAR);
    BIND_ENUM_CONSTANT(INTERP_HERMITE);
    BIND_ENUM_CONSTANT(INTERP_QUINTIC);

    BIND_ENUM_CONSTANT(DISTANCE_EUCLID);
    BIND_ENUM_CONSTANT(DISTANCE_MANHATTAN);
    BIND_ENUM_CONSTANT(DISTANCE_LEASTAXIS);
    BIND_ENUM_CONSTANT(DISTANCE_GREATESTAXIS);

    BIND_ENUM_CONSTANT(BASIS_VALUE);
    BIND_ENUM_CONSTANT(BASIS_GRADIENT);
    BIND_ENUM_CONSTANT(BASIS_SIMPLEX);
}
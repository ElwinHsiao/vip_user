#!/bin/sh

set -eu
shopt -s nullglob

base_dir=$(cd "`dirname "$0"`" && pwd)
djinni_file="$base_dir/vipuser.djinni"
echo "start generate for file: $djinni_file"

out_dir="$base_dir/generated"

cpp_out="$out_dir/cpp"
jni_out="$out_dir/jni"
objc_out="$out_dir/objc"
java_out="$out_dir/java/per/elwin/vipuser/djinni"

java_package="per.elwin.vipuser.djinni"
cpp_namespace="vipuser_djinni"
objc_type_prefix="VPD"

djinni_dir=$base_dir/../third_party/djinni
# Build djinni
"$djinni_dir/src/build"

[[ -e $out_dir ]] && rm -rf $out_dir
"$djinni_dir/src/run-assume-built" \
    --java-out $java_out \
    --java-package $java_package \
    --ident-java-field mFooBar \
    \
    --cpp-out $cpp_out \
    --cpp-namespace $cpp_namespace \
    \
    --jni-out $jni_out \
    --ident-jni-class NativeFooBar \
    --ident-jni-file NativeFooBar \
    \
    --objc-out $objc_out \
    --objcpp-out $objc_out \
    --objc-type-prefix $objc_type_prefix \
    \
    --idl $djinni_file


echo "djinni generate completed."


echo "start android gpy generation..."
make -C $djinni_dir ./deps/gyp



cd $base_dir/..   # the gpy need run from very top directory
ANDROID_BUILD_TOP=$(dirname `which ndk-build`) \
    $djinni_dir/deps/gyp/gyp --depth=. -f android -DOS=android \
    -I$djinni_dir/common.gypi \
    -DDJINNI_DIR=$djinni_dir \
    $base_dir/vipuser.gyp \
    --root-target=libvipuser_jni

if [ -f GypAndroid.mk ]; then
    #mv -f $base_dir/../GypAndroid.mk $base_dir/
    echo "file is generate at: `pwd`/GypAndroid.mk"
else
    echo "gpy generate failed!"
fi


echo "start ios gpy generation..."
$djinni_dir/deps/gyp/gyp --depth=. -f xcode -DOS=ios \
    --generator-output ios \
    -I$djinni_dir/common.gypi \
    -DDJINNI_DIR=$djinni_dir \
    $base_dir/vipuser.gyp



echo "gpy generation finish."

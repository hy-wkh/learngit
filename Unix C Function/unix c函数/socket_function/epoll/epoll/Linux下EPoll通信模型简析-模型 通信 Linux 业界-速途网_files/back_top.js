
var oBackTop = document.getElementById('back-top');
oBackTop.onclick = function(){
    
    doMove(document.body,200,'scrollTop',0);
    doMove(document.documentElement,200,'scrollTop',0);
    
};

window.onload = window.onscroll = window.onresize = function(){
    
    if( scrollY() > 0 ){
        oBackTop.style.display = 'block';   
    }else{
        oBackTop.style.display = 'none';    
    }

    if( isIe6() )oBackTop.style.top = ( view().h - oBackTop.offsetHeight + scrollY() - 10 ) + 'px'; 
    
    
};

function isIe6(){
var str = window.navigator.userAgent.toLowerCase();
if( str.indexOf('msie 6')!=-1)return true;
return false;   
}

function scrollY(){
return document.body.scrollTop || document.documentElement.scrollTop;   
}

function scrollX(){
return document.body.scrollLeft || document.documentElement.scrollLeft; 
}

function view(){
return {
    w: document.documentElement.clientWidth,
    h: document.documentElement.clientHeight    
};
}

function doMove(obj,num,attr,target,fn){

var iCur = getStyle(obj,attr);

num = iCur < target ? Math.abs(num) : -Math.abs(num);

obj.timer = setInterval(function(){

    iCur = getStyle(obj,attr) + num;
        
    if( (num>0 && iCur>=target) || (num<0 && iCur<=target) ){
        iCur = target;
    }
    
    if(obj == document.body || obj == document.documentElement ){
        obj[attr] = iCur;
    }else{
        obj.style[attr] = iCur + 'px';
    }
    
    if( iCur == target ){
        clearInterval(obj.timer);
        if(typeof fn === 'function')fn();   
    }
    
    
},14);


}

function getStyle(obj,attr){

if( obj == document.body || obj == document.documentElement )return scrollY();  

if( obj.currentStyle )return parseFloat( obj.currentStyle[attr] ) || 0;

return parseFloat( getComputedStyle(obj)[attr] ) || 0;
    
}

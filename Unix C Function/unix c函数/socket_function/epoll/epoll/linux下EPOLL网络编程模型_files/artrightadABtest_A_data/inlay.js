!function(t){function e(o){if(n[o])return n[o].exports;var r=n[o]={exports:{},id:o,loaded:!1};return t[o].call(r.exports,r,r.exports,e),r.loaded=!0,r.exports}var n={};return e.m=t,e.c=n,e.p="",e(0)}([function(t,e,n){var o,r,i,a,l,c,u,s,d,h,f;a=n(9),o=n(10),u=n(11),i=n(1),r=n(12),l=n(13),s=function(t,e,n){var o;return o="QIHOO_UNION_"+(new Date).getTime(),"<iframe id="+o+" src="+n+" width="+t+" height="+e+" frameborder=0 marginheight=0 marginwidth=0 scrolling=no align=center,center allowtransparency=true style=display:block;border:none;></iframe>"},d=function(){var t;return t=document.createElement("div"),t.id="QIHOO_UNION_PLACEHOLDER_"+(new Date).getTime()+100*Math.random(),t.style.display="block",t.style.border="none",t.style.boxSizing="content-box",t.style.background="none",t.style.visibility="visible",t},c=function(t){var e,n,a,c;return n=u.getDocumentTitleAndUrl(),a={ls:t.ls,w:t.w,h:t.h,inject:o.inject.INLAY,pos:o.pos.INLAY,rurl:n.url,pn:o.QIHOO_UNION.INLAY,prt:(new Date).getTime(),tit:n.title,pt:o.QIHOO_UNION.PT,cw:window.innerWidth||document.documentElement.clientWidth||document.body.clientWidth,dpr:1,jv:o.jv},i.setStyle(a),"undefined"!=typeof QIHOO_UNION_DEBUG&&null!==QIHOO_UNION_DEBUG&&(o.searchPage=QIHOO_UNION_DEBUG.searchPage),e=o.searchPage+u.serialize(a),c=d(),c.innerHTML=s(t.w,t.h,e),c.setAttribute("data-ls",a.ls),c.setAttribute("data-rurl",a.rurl),document.write(c.outerHTML),r.getPosition()&&l.add(c),o.QIHOO_UNION.INLAY++},f=null!=(h=window.QIHOO_UNION_SLOT)?h:window.QIHOO_union_SLOT,c(f)},function(t,e,n){var o,r,i,a,l,c,u,s;s=n(2),i=n(3),c=n(4),o=n(5),r=n(6),u=n(7),a=n(8),l={setStyle:function(t){var e,n,l,d,h,f,p;switch(t.inject){case 1:return p=s.getLayout(t.w,t.h),l=i.getLayout(t.w,t.h),h=c.getLayout(t.w,t.h),n=r.getLayout(t.w,t.h),f=u.getLayout(t.w,t.h),t.inlay=p.line*p.column,t.link=Math.min(Math.floor(l.line*l.column*1.5),50),t.rank=h.line*h.column,t.imagelink=n.line*n.column,t.searchlink=Math.max(1,f.line*f.column),t;case 2:return e=o.getLayout(t.w,t.h),p=s.getLayout(t.w,t.h),l=i.getLayout(t.w,t.h),h=c.getLayout(t.w,t.h),n=r.getLayout(t.w,t.h),t.inlay=p.line*p.column,t.link=Math.min(Math.floor(l.line*l.column*1.5),50),t.rank=h.line*h.column,t.imagelink=n.line*n.column,t.searchlink=0,t.hao360=e.line*e.column,t;case 3:return d=a.getLayout(t.w,t.h),t.mobilelink=d.column*d.line,t.inlay=0,t.link=0,t.hao360=0,t.rank=0,t.imagelink=0,t.searchlink=0,t;default:return t}}},t.exports=l},function(t,e){var n;n={getLayout:function(t,e){var n,o;switch(o=t+"_"+e){case"300_250":case"250_250":case"640_60":n={column:1,line:3};break;case"160_600":n={column:1,line:7};break;case"960_90":n={column:4,line:1};break;case"336_280":n={column:1,line:4};break;default:n={column:0,line:0}}return n}},t.exports=n},function(t,e){var n;n={getLayout:function(t,e){var n,o,r,i,a,l,c;switch(o=1024>=t&&t>=103&&1024>=e&&e>=28,c=t+"_"+e){case"300_250":case"250_250":case"336_280":r={column:2,line:6};break;case"160_600":r={column:1,line:15};break;case"640_60":r={column:6,line:2};break;case"960_90":r={column:9,line:3};break;default:n=Math.floor(t/103),i=Math.floor(e/28),n*i>50&&(i=Math.floor(50/n)),r={column:n,line:i}}return a=l=4,r.itemWidth=Math.floor((t-a*(r.column-1))/r.column),r.itemHeight=Math.floor((e-l*(r.line-1))/r.line),r.spaceX=Math.floor((t-r.column*r.itemWidth)/(r.column-1)),r.spaceY=Math.floor((e-r.line*r.itemHeight)/(r.line-1)),o||(r.column=r.line=0),Number.isNaN(r.itemWidth)&&(r.itemWidth=0),Number.isNaN(r.itemHeight)&&(r.itemHeight=0),Number.isNaN(r.spaceX)&&(r.spaceX=0),Number.isNaN(r.spaceY)&&(r.spaceY=0),r}},t.exports=n},function(t,e){var n;n={getLayout:function(t,e){var n,o,r,i,a,l,c,u,s,d,h,f;return r=1,s=1,o=t-2*r-2*s,n=e-2*r-2*s,i=Math.floor(t/120),u=Math.floor(e/28),i*u>50&&(u=Math.floor(50/i)),l=Math.floor((n-4*(u-1))/u),c=Math.floor((o-4*(i-1))/i),d=n-u*l,h=o-i*c,f=Math.floor(d/(u-1)),a=Math.floor(h/(i-1)),{line:u,column:i,borderSize:r,padding:s,itemWidth:c,itemHeight:l,rowspan:f,colspan:a,width:o,height:n}}},t.exports=n},function(t,e){var n;n={getLayout:function(t,e){var n,o;return n=48===e,o={column:50,line:1},n||(o={column:0,line:0}),o},getStrlen:function(t){var e,n;return e=t.replace(/[\u4e00-\u9fa5\u3002\u2022]+/g,""),n=(2*t.length-e.length)/2},caculate:function(t,e,n){var o,r,i,a,l,c,u,s,d,h;for(u=t-547-60,c=[],r=[],h=0,s=0,o=0,a=0,l=n.length;l>o;){if(d=this.getStrlen(n[o].tit),i=d*e+20+2,h+=i,u>h?r.push(n[o]):(c.push(r),r=[],h=i,r.push(n[o])),s=u-h,o===l-1)for(a=0;l>a;)d=this.getStrlen(n[a].tit),i=d*e+20+2,s-=i,s>=0?r.push(n[a]):(c.push(r),a=n.length),a++;o++}return{newAds:c}}},t.exports=n},function(t,e){var n;n={getLayout:function(t,e){var n,o,r,i,a,l,c,u,s,d,h,f,p,g,m,y,v,b,w,x,O,M,I;if(s=32,I=86,M=86,O=180,x=180,v=2,w=2,y=20,b=20,r=!1,I>t-4||M>e-4)return{column:0,line:0};for(c=Math.floor(t/I),u=Math.floor(e/M),d=[],m=[],n=function(n,o){var r,i,a,l,c;return r=Math.floor(t/n),i=Math.floor(e/o),i=Math.min(i,Math.floor(s/r)),l=Math.floor((t-n*r)/(r+1)),c=Math.floor((e-o*i)/(i+1)),a=Math.abs(n/(o-20)-1.8),i>0&&r>0&&c>1&&l>1?m.push({column:r,line:i,unitWidth:n,unitHeight:o,spaceX:l,spaceY:c,rate:a}):void 0},o=a=h=I,f=O;f>=a;o=a+=5)for(i=l=p=M,g=x;g>=l;i=l+=5)n(o,i);return d=m.sort(function(t,e){return t.spaceX+t.spaceY-(e.spaceX+e.spaceY)}).slice(0,10).sort(function(t,e){return t.rate-e.rate}),d[0]}},t.exports=n},function(t,e){var n;n={getLayout:function(t,e){var n,o,r,i,a;return o={searchButtonWidth:80,searchButtonHeight:36,bodyPadding:5,bodyBorderSize:1,conMarginBottom:5},o.bodyWidth=t-2*o.bodyBorderSize-2*o.bodyPadding,o.bodyHeight=e-2*o.bodyBorderSize-2*o.bodyPadding,o.conWidth=o.bodyWidth,o.conHeight=Math.max(0,e-o.searchButtonHeight-o.conMarginBottom-2*o.bodyBorderSize-2*o.bodyPadding),n=Math.floor(o.conWidth/120),r=Math.floor(o.conHeight/27),n*r>32&&(r=Math.floor(32/n)),o.column=n,o.line=r,i=a=4,o.itemWidth=Math.floor((o.conWidth-i*(o.column-1))/o.column),o.itemHeight=Math.floor((o.conHeight-a*(o.line-1))/o.line),o.column-1>0?o.spaceX=Math.floor((o.conWidth-o.column*o.itemWidth)/(o.column-1)):o.spaceX=0,o.line-1>0?o.spaceY=Math.floor((o.conHeight-o.line*o.itemHeight)/(o.line-1)):o.spaceY=0,o.column*o.line===0&&(o.conHeight=Math.max(0,e-o.searchButtonHeight-2*o.bodyBorderSize-2*o.bodyPadding)),(0===o.conHeight||200>t)&&(o.column=o.line=0),o}},t.exports=n},function(t,e){var n;n={getLayout:function(t,e,n){var o,r,i,a,l;return o=Math.floor(t/103),i=Math.floor(e/20),o*i>32&&(i=Math.floor(32/o)),r={column:o,line:i},a=l=4,r.itemWidth=Math.floor((t-a*(r.column-1))/r.column),r.itemHeight=Math.floor((e-l*(r.line-1))/r.line),r.spaceX=Math.floor((t-r.column*r.itemWidth)/(r.column-1)),r.spaceY=Math.floor((e-r.line*r.itemHeight)/(r.line-1)),r}},t.exports=n},function(t,e){Array.isArray||(Array.isArray=function(t){return"[object Array]"===Object.prototype.toString.call(t)}),Array.prototype.filter||(Array.prototype.filter=function(t){"use strict";if(void 0===this||null===this)throw new TypeError;var e=Object(this),n=e.length>>>0;if("function"!=typeof t)throw new TypeError;for(var o=[],r=arguments.length>=2?arguments[1]:void 0,i=0;n>i;i++)if(i in e){var a=e[i];t.call(r,a,i,e)&&o.push(a)}return o}),Array.prototype.map||(Array.prototype.map=function(t,e){var n,o,r;if(null==this)throw new TypeError(" this is null or not defined");var i=Object(this),a=i.length>>>0;if("function"!=typeof t)throw new TypeError(t+" is not a function");for(arguments.length>1&&(n=e),o=new Array(a),r=0;a>r;){var l,c;r in i&&(l=i[r],c=t.call(n,l,r,i),o[r]=c),r++}return o}),Array.prototype.reduce||(Array.prototype.reduce=function(t){"use strict";if(null==this)throw new TypeError("Array.prototype.reduce called on null or undefined");if("function"!=typeof t)throw new TypeError(t+" is not a function");var e,n=Object(this),o=n.length>>>0,r=0;if(2==arguments.length)e=arguments[1];else{for(;o>r&&!(r in n);)r++;if(r>=o)throw new TypeError("Reduce of empty array with no initial value");e=n[r++]}for(;o>r;r++)r in n&&(e=t(e,n[r],r,n));return e}),Array.prototype.indexOf||(Array.prototype.indexOf=function(t,e){var n;if(null==this)throw new TypeError('"this" is null or not defined');var o=Object(this),r=o.length>>>0;if(0===r)return-1;var i=+e||0;if(Math.abs(i)===1/0&&(i=0),i>=r)return-1;for(n=Math.max(i>=0?i:r-Math.abs(i),0);r>n;){if(n in o&&o[n]===t)return n;n++}return-1}),Number.isNaN=Number.isNaN||function(t){return"number"==typeof t&&t!==t}},function(t,e,n){var o,r,i,a,l;i=n(11),o={searchPage:"http://api.so.lianmeng.360.cn/searchthrow/api/ads/throw?",mobileSearchPage:"http://api.so.lianmeng.360.cn/searchthrow/api/mads/throw?",positionTrack:"http://s1.stat.lianmeng.360.cn/xy.gif?",pos:{INLAY:0,LEFTBOTTOM:1,RIGHTBOTTOM:2,LEFT:3,RIGHT:4,TOP:5,BOTTOM:6},inject:{INLAY:1,FLOAT:2,MOBILEINLAY:3},jv:"1437124819535",floatPos:["","leftbottom","rightbottom","leftright","left","right","top","bottom","topbottom"],floatOrigin:["","body","browser"],floatDisplay:["","default","onScroll"]},r={PT:(new Date).getTime(),RAND:Math.random()*Math.random()*1e4,INLAY:0,FLOAT:0,MOBILEINLAY:0},i.isInIframe()?(window.QIHOO_UNION=null!=(a=window.QIHOO_UNION)?a:r,o.QIHOO_UNION=window.QIHOO_UNION):(window.top.QIHOO_UNION=null!=(l=window.top.QIHOO_UNION)?l:r,o.QIHOO_UNION=window.top.QIHOO_UNION),t.exports=o},function(t,e){var n,o={}.hasOwnProperty;n={on:function(t,e,n){return window.addEventListener?t.addEventListener(e,n,!1):t.attachEvent("on"+e,n)},isInIframe:function(){var t,e,n,o,r;r=window,o=!1;try{n=r.parent.location.href,r=r.parent}catch(e){t=e,o=!0}return o},getDocumentTitleAndUrl:function(){var t,e,n,o,r,i,a,l,c,u;if(u=window,t=u.document,"[object Function]"!==Object.prototype.toString.call(u.setInterval))l=null!=(r=t.title)?r:"",c=null!=(i=u.location.href)?i:"";else for(o=10;o>0;){try{l=u.document.title,c=u.parent.location.href,u=u.parent}catch(n){e=n,c=u.document.referrer;break}o--}return a={title:l.replace(/\(|\)|>|<|\'|\"/g,""),url:c.replace(/\(|\)|>|<|\'|\"/g,"")}},serialize:function(t){var e,n,r;n=[];for(e in t)o.call(t,e)&&(r=t[e],n.push(e+"="+encodeURIComponent(r).toString().substr(0,512)));return n.join("&")}},t.exports=n},function(t,e,n){var o,r;o=n(10),r={getPosition:function(){return o.QIHOO_UNION.RAND%100<50}},t.exports=r},function(t,e,n){var o,r,i,a;a=n(11),o=n(10),r=n(14),i={add:function(t){var e;return this.res=null!=(e=this.res)?e:[],this.res.push(t),this.fn=function(t){var e,n,r,i,a,l,c,u,s,d,h,f,p,g,m;return p=window,f=Math.max(0,p.innerWidth||p.document.documentElement.clientWidth),h=Math.max(0,p.innerHeight||p.document.documentElement.clientHeight),n=Math.max(0,p.document.documentElement.offsetWidth),e=Math.max(0,p.document.documentElement.offsetHeight),s=Math.max(0,screen.width),u=Math.max(0,screen.height),null!==document.getElementById(t.id)?(a=document.getElementById(t.id).getBoundingClientRect(),g=Math.max(0,a.left),m=Math.max(0,a.top),i=t.getAttribute("data-ls"),c=encodeURIComponent(t.getAttribute("data-rurl")),l=(new Date).getTime(),d=o.positionTrack+("ls="+i+"&rurl="+c+"&x="+g+"&y="+m+"&vw="+f+"&vh="+h+"&dw="+n+"&dh="+e+"&sw="+s+"&sh="+u+"&_r="+l),r=new Image,r.onload=r.onerror=function(){return r=null},r.src=d):void 0},"init"!==this.domready?(this.domready="init",r(function(t){return function(){var e,n,o,r,i;for(r=t.res,i=[],e=0,o=r.length;o>e;e++)n=r[e],i.push(t.fn(n));return i}}(this))):void 0}},t.exports=i},function(t,e,n){/*!
	  * domready (c) Dustin Diaz 2012 - License MIT
	  */
!function(e,n){t.exports=n()}("domready",function(t){function e(t){for(f=1;t=o.shift();)t()}var n,o=[],r=!1,i=document,a=i.documentElement,l=a.doScroll,c="DOMContentLoaded",u="addEventListener",s="onreadystatechange",d="readyState",h=l?/^loaded|^c/:/^loaded|c/,f=h.test(i[d]);return i[u]&&i[u](c,n=function(){i.removeEventListener(c,n,r),e()},r),l&&i.attachEvent(s,n=function(){/^c/.test(i[d])&&(i.detachEvent(s,n),e())}),t=l?function(e){self!=top?f?e():o.push(e):function(){try{a.doScroll("left")}catch(n){return setTimeout(function(){t(e)},50)}e()}()}:function(t){f?t():o.push(t)}})}]);